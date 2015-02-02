/*
============================================================================
 Name        : MemAlignMalloc.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : PROBLEM 2
	In C programming, you've probably used the following two functions from stdlib.h to respectively allocate and deallocate
	memory from the heap:
	void * malloc(size_t size);
	void free(void *ptr);
The C language specification does not specify certain properties of memory allocated by malloc.  One of these unspecified
properties is whether the allocated memory is aligned.  An n-byte aligned address is defined as an address that is a multiple
of n bytes, where n is restricted to be a power of 2.  An n-byte aligned address is also sometimes referred to as an address
that falls on a n-byte boundary.
Your job is to implement a pair of functions that allocate and deallocate memory like malloc and free, but return addresses that
aligned to an n-byte boundary, where n is again guaranteed to be a power of 2.  Use the following two prototypes as a reference:
   void * aligned_malloc(size_t size, size_t alignment);
   void aligned_free(void * ptr);
You may use malloc and free to implement your solution.  Implement these, along with a small main() function that demonstrates
their use.  Your solution should be a single C source file that may be compiled using a standard C compiler.
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define META_DATA_SIZE 	(sizeof(unsigned int))
#define ORIG_PTR_OFFSET	(-1)

void * aligned_malloc(size_t size, size_t alignment);
void aligned_free(void * ptr);

void * aligned_malloc(size_t size, size_t alignment)
{
	assert ((alignment & (alignment - 1)) == 0);	//ensure 2's power
	//minimum alignment at int size boundary. this was not asked for in the question but most hardware will require it
	alignment = (sizeof(int) > alignment) ? sizeof(int) : alignment;

	unsigned int totalSize  = size + alignment;
	void * memPtr = malloc(totalSize);	//Assumption: aligned_malloc will behave the same way as underlying malloc in case of trying to allocate 0 bytes
	if (!memPtr) return memPtr;	//out of memory

    unsigned int alignedAddr = (unsigned int)(memPtr);
    alignedAddr += (alignment + META_DATA_SIZE);
    alignedAddr &= ~(alignment - 1);

    // Store original pointer just before aligned address
    // Will need this to free the buffer
    unsigned int * alignedPtr = (unsigned int *)(alignedAddr);
    alignedPtr[ORIG_PTR_OFFSET] = (unsigned int)(memPtr);

    return alignedPtr;
}

void aligned_free(void * ptr)
{
    if (ptr != NULL)
    {
        unsigned int * alignedPtr = (unsigned int*)(ptr);
        void * origPtr = (void *)(alignedPtr[ORIG_PTR_OFFSET]);
        free(origPtr);
    }
}

int main(void)
{
	printf("My Aligned Memory Management implementation:\n");
	int size, align;
	unsigned int *address;

	size = 0x50;
	align = 0x10;
	address = aligned_malloc(size, align);
	printf("%x, %x: %x\n", size, align, (int)(address));
	aligned_free(address);

	size = 0x50;
	align = 0x1000;
	address = aligned_malloc(size, align);
	printf("%x, %x: %x\n", size, align, (int)(address));
	aligned_free(address);


	size = 0x0;
	align = 0x0;
	address = aligned_malloc(size, align);
	printf("%x, %x: %x\n", size, align, (int)(address));
	aligned_free(address);


	size = 0x0;
	align = 0x10;
	address = aligned_malloc(size, align);
	printf("%x, %x: %x\n", size, align, (int)(address));
	aligned_free(address);

	size = 0x1;
	align = 0x00;
	address = aligned_malloc(size, align);
	printf("%x, %x: %x\n", size, align, (int)(address));
	aligned_free(address);

	return EXIT_SUCCESS;
}




