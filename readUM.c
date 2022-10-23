/*
 * Name: readUM.c 
 *
 * Comp40: Homework 06 
 *
 * Prupose Contains the implementation for the readUM function which 
 *         reads in words from a file and places them in memory
 * 
 * Authors: Quinnten Silveira-Charbonnier, Haijun 
 */

#include "memory.h"
#include "assert.h"
#include "bitpack.h"
#include <stdio.h>

#define WORD_LEN 4
#define BYTE_SIZE 8

/* Name: readUM
 * 
 * Purpose: To read in a bytes from a file and put them into words. And then 
 *          place those words into memory. 
 * 
 * Parameters: A file pointer and a file size int. 
 *
 * Return: Void, but memory will be initalized.
 */
Memory readUM(FILE *inputfd, int file_size)
{
    /* assert that the number of bytes in the file is divisable by 4 */
    assert(file_size % WORD_LEN == 0);

    int words = file_size / WORD_LEN;
    /* Create the memory to hold all the words */
    Memory um_program = mem_NEW();

    /* Maps the 0 segment*/
    map_SEGMENT(um_program, words);

    for (int i = 0; i < words; i++) {
        uint32_t word = 0;

        /* put bytes into word in big endian order*/
        for (int j = 3; j >= 0; j--) {
            uint32_t byte = fgetc(inputfd);
            word = Bitpack_newu(word, BYTE_SIZE, j * BYTE_SIZE, byte);
        }
        /* Put word into memory */
        put_WORD(um_program, 0, i, word);
    }
    return um_program;
}