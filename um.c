/*
 * Name: um.c 
 *
 * Comp40: Homework 06 
 *
 * Prupose Driver of the program. Contains the main function calls the 
 *         readUM and execute functions
 * 
 * Authors: Quinnten Silveira-Charbonnier, Haijun 
 */
 
#include "memory.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


Memory readUM(FILE *inputfd, int file_size);
void execute(Memory prog);

/* Name: get_FILESIZE
 * 
 * Purpose: To read the length of a file in bytes. 
 * 
 * Parameters: A file pointer 
 *
 * Return: The size of the file in bytes represented by an int
 */
int get_FILESIZE(char *file)
{
    /* READS FILE BYTE SIZE!!!!!!!! */
    struct stat sb;
    
    if (stat(file, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    printf("File size: %lld bytes\n", (long long) sb.st_size);
    return sb.st_size;
}


int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        printf("too many inputs\n");
    }

    char *filename = argv[1];
    int file_size = get_FILESIZE(filename);

    /* Initialize memory */
    FILE *file = fopen(filename, "rb");
    Memory program = readUM(file, file_size);
    fclose(file);

    /* Run instructions */
    execute(program);
    return EXIT_SUCCESS;
}