#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>

typedef struct CircularBufferStruct* CircularBuffer;

CircularBuffer CircularBuffer_create(unsigned int capacity);
void CircularBuffer_destroy(CircularBuffer buffer);

void CircularBuffer_push(CircularBuffer buffer, int value);
int CircularBuffer_pop(CircularBuffer buffer);

unsigned int CircularBuffer_capacity(CircularBuffer buffer);
unsigned int CircularBuffer_size(CircularBuffer buffer);
bool CircularBuffer_full(CircularBuffer buffer);
bool CircularBuffer_empty(CircularBuffer buffer);

#endif
