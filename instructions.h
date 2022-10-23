/*
 * Name: instructions.h 
 *
 * Comp40: Homework 06 
 *
 * Prupose: Contains the interface for the instructions.c file. Contains 
 *          all the opcode instructions. 
 * 
 * Authors: Quinnten Silveira-Charbonnier, Haijun 
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "memory.h"
#include "registers.h"
#include "bitpack.h"
#include "math.h"

struct Three_registers {
    uint32_t ra, rb, rc;
};

struct Three_registers get_threeREGS(uint32_t word);

void CMOV(uint32_t word, Registers r);

void SLOAD(uint32_t word, Registers r, Memory m);

void SSTORE(uint32_t, Registers r, Memory m);

void ADD(uint32_t word, Registers r);

void MUL(uint32_t word, Registers r);

void DIV(uint32_t word, Registers r);

void NAND(uint32_t word, Registers r);

void HALT();

void ACTIVATE(uint32_t word, Registers r, Memory m);

void INACTIVATE(uint32_t word, Registers r, Memory m);

void INPUT(uint32_t word, Registers r);

void OUTPUT(uint32_t word, Registers r);

void LOADP(uint32_t word, Registers r, Memory m, int *counter);

void LV(uint32_t word, Registers r);