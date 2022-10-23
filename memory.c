/*
 * Name: memory.c 
 *
 * Comp40: Homework 06 
 *
 * Authors: Quinnten Silveira-Charbonnier, Haijun 
 * 
 * Purpose: The complete implementation to the memory.c
 */

#include "memory.h"

#define WORD_SIZE 32
#define INIT_SIZE 1

struct Memory {
    int prog_WORDS;
    Seq_T mem;
    Seq_T reusable_segs;
};

/* Name: mem_NEW
 * 
 * Purpose: to create an new instance of a Memory struct
 * 
 * Parameters: none
 *
 * Return: A new instance of a Memory struct
 */ 
Memory mem_NEW()
{
    Memory memory;
    NEW(memory);

    assert(memory != NULL);
    /* Initialize Memory Sequences */
    memory->mem = Seq_new(INIT_SIZE);
    memory->reusable_segs = Seq_new(INIT_SIZE);

    /* Return memory struct */
    return memory;
}

/* Name: mem_FREE
 * 
 * Purpose: to free an instance of a Memory struct 
 * 
 * Parameters: A Memory struct 
 *
 * Return: void, but the Memory struct has been freed
 */ 
void mem_FREE(Memory mem)
{
    /* What if there is a shit ton of segments*/
    int length = mem_LEN(mem);
    for (int i = 0; i < length; i ++)
    {
        /* Takes a segment in the memory sequence*/
        UArray_T segment = (UArray_T) Seq_get(mem->mem, i);
        if (segment != NULL) {
            /* Frees the segment */
            UArray_free(&segment);
        }
    }
    /* Unused resuable segment IDs*/
    int x = get_REUSABLE(mem);

    while (x != 0) {
        get_REUSABLE(mem);
    }
    
    /* Free the memory sequence and the structs */
    Seq_free(&(mem->mem));
    Seq_free(&(mem->reusable_segs));
    FREE(mem);
}

/* Name: mem_progWORDS
 * 
 * Purpose: to return the value of the number of words in the program that 
 *          need to be read. 
 * 
 * Parameters: A Memory struct
 *
 * Return: the prog_WORDS variable in the Memory struct
 */ 
int mem_progWORDS(Memory mem)
{
    assert(mem != NULL);
    return mem->prog_WORDS;
}

/* Name: mem_LEN
 * 
 * Purpose: return the number of segments in the mem sequence
 * 
 * Parameters: A Memory struct
 *
 * Return: The number of segements in the mem sequence
 */ 
int mem_LEN(Memory mem)
{
    assert(mem != NULL);
    return Seq_length(mem->mem);
}

/* Name: add_REUSABLE 
 * 
 * Purpose: To add the index of a reusable segemnt into the reusalble_segs 
 *  1       sequecne 
 * 
 * Parameters: A Memeory struct "m" and the segmentID "segID"
 *
 * Return: void, but the sequecne reusuable_segs has been updated
 */ 
void add_REUSABLE(Memory m, uint32_t segID)
{
    int *ID;
    NEW(ID);
    *ID = segID;
    Seq_addhi(m->reusable_segs, ID);
}

/* Name: get_REUSABLE
 * 
 * Purpose: To check the reusable_gets sequence if there exists a reusbale ID
 * 
 * Parameters: A Memory struct "mem"
 *
 * Return: An resuable segment ID if one exists or zero otherwise. 
 */ 
int get_REUSABLE(Memory mem)
{
    if (Seq_length(mem->reusable_segs) == 0)
    {
        return 0;
        /* If sequence has no elements, return zero */
    }
    int *x = (int *) Seq_remlo(mem->reusable_segs);
    int y = *x;
        /* If the sequence has any elements, remove t
         * he lowest index and return it 
         */
    FREE(x);
    return y;
}

/* Name: map_SEGEMENT
 * 
 * Purpose: Create a new sgement in the memory sequence
 * 
 * Parameters: A Memory struct and number of words in the segment represented 
 *             by a uint32_t
 *
 * Return: Void, but a new memory segement is added to memory sequence. 
 */ 
void map_SEGMENT(Memory mem, uint32_t num_words)
{
    
    int length = mem_LEN(mem);
    
     /* If suquence is empty, create segment zero with num words*/
    if (length == 0) {                    
        mem->prog_WORDS = num_words;
    }
    
    /* Check if any reusable segments IDs exist */
    int reusableID = get_REUSABLE(mem);
    /* Creates a new segment with the amount of 32-bit words */
    UArray_T new_seg = UArray_new(num_words, WORD_SIZE);
    /* Checks if the segment can be placed in a resuable part of the memory */
    if (reusableID == 0) {
        Seq_addhi(mem->mem, new_seg);
    } else {
        Seq_put(mem->mem, reusableID, new_seg);
    } 

}

/* Name: unmap_SEGMENT
 * 
 * Purpose: To unmap a segment of memory. 
 * 
 * Parameters: A Memory struct mem, and a segemtn ID represented as a uint32_t
 *
 * Return: Void, but a segement of memeory has been unmapped and the index 
 *         has been added to the resuable_segs sequence. 
 */ 
void unmap_SEGMENT(Memory mem, uint32_t segID)
{
    /* Makes in bounds */
    int length = mem_LEN(mem);
    assert (length > (int) segID);
    /* Takes the old segment to free */
    UArray_T old_seg = Seq_get(mem->mem, segID);
    Seq_put(mem->mem, segID, NULL);
    UArray_free(&old_seg);

    add_REUSABLE(mem, segID);
}

/* Name: put_WORD
 * 
 * Purpose: Add a word to a segment in memory 
 * 
 * Parameters: A Memory struct, a segment ID, an Index in the segment, and 
 *             a word 
 *
 * Return: Void, but a word has been added to memory
 */ 
void put_WORD(Memory mem, uint32_t segID, uint32_t index, uint32_t word)
{
    
    UArray_T seg = Seq_get(mem->mem, segID);
    /* Gets the place to add the word */
    uint32_t *temp = UArray_at(seg, index);
    *temp = word;
}

/* Name: get_WORD
 * 
 * Purpose: to get a word from memory
 * 
 * Parameters: A Memory struct, a segment ID, and index in the segment
 *
 * Return: A uint32_t word
 */ 
uint32_t get_WORD(Memory mem, uint32_t segID, uint32_t index)
{
    /* Gets the index of the word in the segment */
    UArray_T seg = Seq_get(mem->mem, segID);
    uint32_t *word = UArray_at(seg, index);
    /* Returns the word */ 
    return *word;
}

/* Name: dup_PROG
 * 
 * Purpose: to duplicate a segment and replace the 0 segment with the 
 *          duplicated segment. 
 * 
 * Parameters: A Memory struct and a segment ID
 *
 * Return: Void, but the 0 segment in memory has been replaced with the 
 *         duplacted segement. 
 */ 
void dup_PROG(Memory m, uint32_t segID)
{
    UArray_T Array = Seq_get(m->mem, segID);
    int num_words = UArray_length(Array);
    unmap_SEGMENT(m, 0);
    map_SEGMENT(m, num_words);

    for (int i = 0; i < num_words; i++) {
        uint32_t word = get_WORD(m, segID, i);
        put_WORD(m, 0, i, word);
    }

}

