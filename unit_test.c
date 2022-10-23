#include <stdio.h>
#include <stdlib.h>
#include "registers.h"
#include "memory.h"
#include "assert.h"

void registers_tests()
{
    Registers regs = reg_NEW();
    reg_PUT(regs, 5, 200);
    int five = reg_GET(regs, 5);
    assert(five == 200);
    
    reg_FREE(regs);
}

void memory_tests()
{
    Memory mem = mem_NEW();
    // assert(Seq_length(mem->mem == 1));

    /* ERROR: Assert segID > 0 */
    map_SEGMENT(mem, 16);
    map_SEGMENT(mem, 16);
    map_SEGMENT(mem, 0);
    // assert(Seq_length(mem->mem == 2));

    unmap_SEGMENT(mem, 1);
    // assert(Seq_length(mem->mem == 1));

    map_SEGMENT(mem, 32);

    put_WORD(mem, 1, 4, 50);
    get_WORD(mem, 1, 4);
    
    add_REUSABLE(mem, 3);

    assert(get_REUSABLE(mem) == 3);

    unmap_SEGMENT(mem, 0); 
    /* This test should crash the program*/
    
    mem_FREE(mem);

}
int main()
{
    // registers_tests();
    memory_tests();
}

