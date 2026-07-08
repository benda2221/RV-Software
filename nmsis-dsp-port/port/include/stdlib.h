#ifndef ZIRCON_PORT_STDLIB_H
#define ZIRCON_PORT_STDLIB_H

#include <stddef.h>
#include <stdint.h>

#define RAND_MAX 0x7fffffff
int rand(void);
void srand(unsigned int seed);
int abs(int value);
long labs(long value);
void *malloc(size_t size);
void free(void *pointer);

#endif
