
#include "RingBuffer.h"

RingBuffer::RingBuffer(size_t max_length) :
		max_length(max_length),
		current_length(max_length),
		head(max_length - 1u),
		tail(0)
	{
		buffer = new float[max_length];

		for (size_t i = 0; i < max_length; ++i) {
	  		buffer[i] = 0.f;
		}
}

RingBuffer::~RingBuffer() {
	delete buffer;
}

bool RingBuffer::resize(size_t new_length)
{
	if (new_length > max_length) {
		return false;
	}

	current_length = new_length;
	return true;
}

void RingBuffer::update(float sample)
{
	buffer[head] = sample;
	head = (head + 1u) % current_length;
	tail = (tail + 1u) % current_length;
}

float RingBuffer::get(float offset)
{
	// Yep, fractional length is possible :) This is useful for variations of Karplus Strong model (keytar) algorithms, time-stretching based pitch shift etc.
	float fracPart = fmodf(offset, 1);

	return 	(1.f - fracPart) * buffer[(tail + (int32_t)offset) % current_length] +
		 		(      fracPart) * buffer[(tail + (int32_t)offset + 1u) % current_length];
}
