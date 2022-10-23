/*
 * Name: Memory.h 
 *
 * Comp40: Homework 06 
 *
 * Prupose Contains the interface for the memory.c file and contains all the 
 *         functions necessary to run a Memory struct
 * 
 * Authors: Quinnten Silveira-Charbonnier, Haijun 
 */

#ifndef MEMORY_INCLUDED
#define MEMORY_INCLUDED 

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "seq.h"
#include "uarray.h"
#include "mem.h"
#include "assert.h"

typedef struct Memory *Memory;

/* ALLOC AND FREE */
extern Memory mem_NEW();

extern void mem_FREE(Memory mem);

extern int mem_progWORDS(Memory mem);

extern int mem_LEN(Memory mem);

extern void map_SEGMENT(Memory mem, uint32_t num_words);

extern void unmap_SEGMENT(Memory mem, uint32_t segID);

extern void put_WORD(Memory mem, uint32_t segID, uint32_t index, uint32_t word);

extern uint32_t get_WORD(Memory mem, uint32_t segID, uint32_t index);

extern void dup_PROG(Memory m, uint32_t segID);

extern void add_REUSABLE(Memory m, uint32_t segID);

extern int get_REUSABLE(Memory mem);

// add, get, and remove from reusable sequence


#endif