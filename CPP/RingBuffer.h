/*
  ==============================================================================

    RingBuffer.h
    Created: 23 May 2020 12:32:09pm
    Author:  mw

  ==============================================================================
*/

#pragma once

#include <cstdint>
#include <memory>
#include <cmath>

class RingBuffer
{
private:
	float* buffer;
	size_t max_length;
	size_t current_length;
	size_t head;
	size_t tail;

public:
	RingBuffer(size_t max_len);
	~RingBuffer();

	bool resize(size_t len);

	void update(float new_sample);

	float get(float offset = 0);
};
