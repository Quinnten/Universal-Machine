/*
 * Name: registers.h 
 *
 * Comp40: Homework 06 
 *
 * Purpose: The interface for the Registers.c file. Lists all the 
 *          functions necessary to run a complete Registers struct. 
 *
 * Authors: Quinnten Silveira-Charbonnier, Haijun 
 */
 
#ifndef REGISTERS_INCLUDED
#define REGISTERS_INCLUDED 

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "uarray.h"
#include "mem.h"
#include "assert.h"


struct Registers;
typedef struct Registers *Registers;

extern Registers reg_NEW();

extern uint32_t reg_GET(Registers registers, int index);

extern void reg_PUT(Registers registers, int index, uint32_t value);

extern void reg_FREE(Registers registers);

#endif