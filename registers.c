/*
 * Name: registers.c 
 *
 * Comp40: Homework 06 
 *
 * Purpose: Implementation to the registers.h file. Contains all the functions
 *          necessary to run a complete Registers struct
 *
 * Authors: Quinnten Silveira-Charbonnier, Haijun 
 */
 
#include "registers.h"
 
struct Registers {
    UArray_T array;
};

#define SIZE 32
#define LEN 8

/* Name: reg_NEW
 * 
 * Purpose: creates a new instance of the Registers struct
 * 
 * Parameters: none
 *
 * Return: A new registers struct
 */ 
Registers reg_NEW() 
{
    Registers registers; 
    NEW(registers);
    
    assert(registers != NULL);

    registers->array = UArray_new(LEN, SIZE); /* Initialize array */
    
    return registers;
}

/* Name: reg_GET 
 * 
 * Purpose: to get a uint32_t located at a particular index
 * 
 * Parameters: A Registers struct and an index of the desired register
 *
 * Return: An int32_t located at index "index"
 */ 
uint32_t reg_GET(Registers registers, int index)
{
    assert(registers != NULL);
    assert(index >= 0 && index < 8);
    
    uint32_t *value = UArray_at(registers->array, index);

    return *value;
}

/* Name: reg_PUT
 * 
 * Purpose: put a uint32_2 at an index in a Registers struct
 * 
 * Parameters: A Registers struct, an index, and a value to be placed at that 
 *             index. 
 *
 * Return: void, but a Registers at index "index" has been updated
 */ 
void reg_PUT(Registers registers, int index, uint32_t value)
{
    assert(registers != NULL);
    uint32_t *reg = UArray_at(registers->array, index);
    *reg = value;
}

/* Name: reg_FREE
 * 
 * Purpose: free an instance of a Registers struct
 * 
 * Parameters: A Registers struct
 *
 * Return: void, but the Registers struct has been freed
 */ 
void reg_FREE(Registers registers)
{
    assert(registers != NULL);
    
    UArray_free(&registers->array);
    FREE(registers);
}

 