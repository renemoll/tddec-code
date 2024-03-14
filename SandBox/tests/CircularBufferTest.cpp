
extern "C" {
#include "CircularBuffer.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(CircularBuffer)
{
	CircularBuffer buffer;

	void setup()
	{
		buffer = CircularBuffer_create(10U);
	}

	void teardown() {
		CircularBuffer_destroy(buffer);
	}
};

TEST(CircularBuffer, Initialization)
{
	// Prepare
	// Execute
	// Verify
	CHECK_FALSE(buffer == NULL);
	CHECK_EQUAL(10, CircularBuffer_capacity(buffer));
}

TEST(CircularBuffer, NewBufferIsEmpty)
{
	/*
	 * Note: I am opting to combine empty, full and size here as they complent each other.
	 */

	// Prepare
	// Execute
	// Verify
	CHECK_TRUE(CircularBuffer_empty(buffer));
	CHECK_FALSE(CircularBuffer_full(buffer));
	CHECK_EQUAL(0, CircularBuffer_size(buffer));
}

TEST(CircularBuffer, PushOneValue)
{
	// Prepare
	// Execute
	CircularBuffer_push(buffer, 1);

	// Verify
	CHECK_FALSE(CircularBuffer_empty(buffer));
	CHECK_FALSE(CircularBuffer_full(buffer));
	CHECK_EQUAL(1, CircularBuffer_size(buffer));
}

TEST(CircularBuffer, PopOneValue)
{
	// Prepare
	CircularBuffer_push(buffer, 33);

	// Execute
	int result = CircularBuffer_pop(buffer);

	// Verify
	CHECK_EQUAL(33, result);
	CHECK_TRUE(CircularBuffer_empty(buffer));
	CHECK_FALSE(CircularBuffer_full(buffer));
	CHECK_EQUAL(0, CircularBuffer_size(buffer));
}

TEST(CircularBuffer, PushUntilFull)
{
	// Prepare
	// Execute
	for (unsigned int i = 0; i < CircularBuffer_capacity(buffer); ++i) {
		CircularBuffer_push(buffer, i);
	}
	
	// Verify
	CHECK_FALSE(CircularBuffer_empty(buffer));
	CHECK_TRUE(CircularBuffer_full(buffer));
	CHECK_EQUAL(10, CircularBuffer_size(buffer));
}

TEST(CircularBuffer, PopUntilEmpty)
{
	// Prepare
	for (unsigned int i = 0; i < CircularBuffer_capacity(buffer); ++i) {
		CircularBuffer_push(buffer, i);
	}

	// Execute
	for (unsigned int i = 0; i < CircularBuffer_capacity(buffer); ++i) {
		CHECK_EQUAL((int)i, CircularBuffer_pop(buffer));
	}
	
	// Verify
	CHECK_TRUE(CircularBuffer_empty(buffer));
	CHECK_FALSE(CircularBuffer_full(buffer));
	CHECK_EQUAL(0, CircularBuffer_size(buffer));
}
