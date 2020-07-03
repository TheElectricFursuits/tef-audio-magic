/*
  ==============================================================================

    CombFilter.h
    Created: 10 Jun 2020 5:11:52pm
    Author:  mw

  ==============================================================================
*/

#pragma once

#include <cstdint>
#include <memory>
#include <cmath>

#include "RingBuffer.h"

class CombFilter
{
private:
	RingBuffer buffer;

public:
	CombFilter(size_t max_len = 44100);

	bool resize(size_t new_length);
	float update(float new_sample);
};
