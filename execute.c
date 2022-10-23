/*
 * Name: execute.c 
 *
 * Comp40: Homework 06 
 *
 * Prupose Contains the execute function which consists of a large query 
 *         that takes in words as long as there are words in segmetn 0 to be 
 *         read. 
 * 
 * Authors: Quinnten Silveira-Charbonnier, Haijun 
 */
 
#include <stdlib.h>
#include <inttypes.h>
#include "memory.h"
#include "registers.h"
#include "bitpack.h"
#include "instructions.h"


#define op_WIDTH 4
#define op_LSB 28

typedef enum Um_opcode {
        op_CMOV = 0, op_SLOAD, op_SSTORE, op_ADD, op_MUL, op_DIV,
        op_NAND, op_HALT, op_ACTIVATE, op_INACTIVATE, op_OUT, op_IN, 
        op_LOADP, op_LV
} Um_opcode;

/* Name: execute 
 * 
 * Purpose: To read from memeory segemnt 0 and preform each operation 
 *          until counter exceeds the number of words in the program
 * 
 * Parameters: A Memory struct 
 *
 * Return: Void, but when the function ends, the program instructions 
 *         should be completley executed
 */
void execute(Memory program)
{
    Registers registers = reg_NEW();
    (void) registers;
    int prog_COUNTR = 0;
    int num_INSTRCNS = mem_progWORDS(program);
    
    while (prog_COUNTR < num_INSTRCNS)
    {
        /* Get opcode */
        uint32_t word = get_WORD(program, 0, prog_COUNTR);
        uint32_t opcode = Bitpack_getu(word, op_WIDTH, op_LSB);
        
        
        /* Large if statement that calls command depending on the opcode*/
        if (opcode == op_CMOV) {
            CMOV(word, registers);
        } else if (opcode == op_SLOAD) {
            SLOAD(word, registers, program);
        } else if (opcode == op_SSTORE) {
            SSTORE(word, registers, program);
        } else if (opcode == op_ADD) {
            ADD(word, registers);
        } else if (opcode == op_MUL) {
            MUL(word, registers);
        } else if (opcode == op_DIV) {
            DIV(word, registers);
        } else if (opcode == op_NAND) {
            NAND(word, registers);
        } else if (opcode == op_HALT) {
            HALT();
        } else if (opcode == op_ACTIVATE) {
            // ACTIVATE(word, registers);
        } else if (opcode == op_INACTIVATE) {
            // INACTIVATE(word, registers);
        } else if (opcode == op_OUT) {
            OUTPUT(word, registers);
        } else if (opcode == op_IN) {
            printf("called IN\n");
        } else if (opcode == op_LOADP) {
            printf("called LOADP\n");
        } else if (opcode == op_LV) {
            LV(word, registers);

        } else {
            printf("opcode is %d\n", opcode);
        }
        /* what if opcode = 15? or 14*/
        num_INSTRCNS = mem_progWORDS(program);
        prog_COUNTR++;
    }
    mem_FREE(program);
    reg_FREE(registers);
}