
#include "CircularBuffer.h"

#include <string.h>

typedef struct CircularBufferStruct {
	unsigned int m_head;
	unsigned int m_tail;
	unsigned int m_capacity;
	bool m_full;
	int* m_data;
} CircularBufferStruct;

CircularBuffer CircularBuffer_create(unsigned int capacity)
{
	CircularBuffer cb = (CircularBuffer)malloc(sizeof(CircularBufferStruct));
	cb->m_head = 0;
	cb->m_tail = 0;
	cb->m_capacity = capacity;
	cb->m_full = false;
	cb->m_data = calloc(capacity, sizeof(int));
	return cb;
}

void CircularBuffer_destroy(CircularBuffer buffer)
{
	free(buffer->m_data);
	free(buffer);
}

void CircularBuffer_push(CircularBuffer buffer, int value)
{
	buffer->m_data[buffer->m_head] = value;
	if (buffer->m_full)
		buffer->m_tail = (buffer->m_tail + 1) % buffer->m_capacity;
	buffer->m_head = (buffer->m_head + 1) % buffer->m_capacity;
	buffer->m_full = buffer->m_head == buffer->m_tail;
}

int CircularBuffer_pop(CircularBuffer buffer)
{
	if (CircularBuffer_empty(buffer))
		return 0;

	int value = buffer->m_data[buffer->m_tail];
	buffer->m_tail = (buffer->m_tail + 1) % buffer->m_capacity;
	buffer->m_full = false;
	return value;
}

unsigned int CircularBuffer_capacity(CircularBuffer buffer)
{
	return buffer->m_capacity;
}

unsigned int CircularBuffer_size(CircularBuffer buffer)
{
	if (buffer->m_full)
		return buffer->m_capacity;

	if (buffer->m_head >= buffer->m_tail)
		return buffer->m_head - buffer->m_tail;
	return buffer->m_capacity - buffer->m_tail + buffer->m_head;
}

bool CircularBuffer_full(CircularBuffer buffer)
{
	return buffer->m_full;
}

bool CircularBuffer_empty(CircularBuffer buffer)
{
	return !buffer->m_full && (buffer->m_head == buffer->m_tail);
}
