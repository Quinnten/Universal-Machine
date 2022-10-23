/*
 * Name: instructions.c 
 *
 * Comp40: Homework 06 
 *
 * Prupose Contains the full implementation of the intructions.h file. 
 * 
 * Authors: Quinnten Silveira-Charbonnier, Haijun 
 */
 
#include <stdlib.h>
#include <stdio.h>
#include "memory.h"
#include "registers.h"
#include "bitpack.h"
#include "math.h"

struct Three_registers {
    uint32_t ra, rb, rc;
};

/* Name: get_threeREGS
 * 
 * Purpose: To use unbitpacking techniques to initalize a Three_registers 
 *          struct.
 * 
 * Parameters: A uint32_t word 
 *
 * Return: a initalized Three_registers struct
 */
struct Three_registers get_threeREGS(uint32_t word);

/* Name: CMOV
 * 
 * Purpose: To execute the coniditonal move operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct.
 *
 * Return: Void, but the Registers might be updated.
 */
void CMOV(uint32_t word, Registers r);

/* Name: SLOAD
 * 
 * Purpose: To execute the segment load operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct, and a Memory struct
 *
 * Return: Void, but the Registers and Memory will be updated.
 */
void SLOAD(uint32_t word, Registers r, Memory m);

/* Name: SSTORE
 * 
 * Purpose: To execute the segment store operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct, and a Memory struct
 *
 * Return: Void, but the Registers and Memory will be updated.
 */
void SSTORE(uint32_t, Registers r, Memory m);

/* Name: ADD
 * 
 * Purpose: To execute the addition operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct.
 *
 * Return: Void, but the Registers will be updated.
 */
void ADD(uint32_t word, Registers r);

/* Name: MUL
 * 
 * Purpose: To execute the multiplication operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct.
 *
 * Return: Void, but the Registers will be updated.
 */
void MUL(uint32_t word, Registers r);

/* Name: DIV
 * 
 * Purpose: To execute the division operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct.
 *
 * Return: Void, but the Registers will be updated.
 */
void DIV(uint32_t word, Registers r);

/* Name: NAND
 * 
 * Purpose: To execute the Not And operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct.
 *
 * Return: Void, but the Registers will be updated.
 */
void NAND(uint32_t word, Registers r);

/* Name: HALT
 * 
 * Purpose: To execute the halt operation 
 * 
 * Parameters: None
 *
 * Return: Exits program
 */
void HALT();

/* Name: ACTIVATE 
 * 
 * Purpose: To execute the activation operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct, and a Memory struct
 *
 * Return: Void, but the Registers and Memory will be updated.
 */
void ACTIVATE(uint32_t word, Registers r, Memory m);

/* Name: INACTIVATE
 * 
 * Purpose: To execute the inactivate operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct, and a Memory struct
 *
 * Return: Void, but the Registers and Memory will be updated.
 */
void INACTIVATE(uint32_t word, Registers r, Memory m);

/* Name: INPUT
 * 
 * Purpose: To execute the input operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct.
 *
 * Return: Void, but the Registers will be updated.
 */
void INPUT(uint32_t word, Registers r);

/* Name: OUTPUT
 * 
 * Purpose: To execute the output operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct.
 *
 * Return: Void, but the Registers will be updated.
 */
void OUTPUT(uint32_t word, Registers r);

/* Name: LOADP
 * 
 * Purpose: To execute the load program operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct, and a Memory struct, 
 *             and an int-pointer counter 
 *
 * Return: Void, but the Registers, the counter, and Memory will be updated.
 */
void LOADP(uint32_t word, Registers r, Memory m, int *counter);

/* Name: LV
 * 
 * Purpose: To execute the load value operation 
 * 
 * Parameters: A unit32_t word, and a Registers struct.
 *
 * Return: Void, but the Registers will be updated.
 */
void LV(uint32_t word, Registers r);




