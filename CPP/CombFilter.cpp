

#include "CombFilter.h"

CombFilter::CombFilter(size_t max_length) :
	buffer(RingBuffer(max_length)) {
	buffer.resize(1000);
}

bool CombFilter::resize(size_t new_length) {
	return buffer.resize(new_length);
}

float CombFilter::update(float sample) {
	for (int i = 0; i < 8; ++i) {
		buffer.update(sample);
		sample = 0.5f * sample + 0.5f * buffer.get(0);
	}

	return sample;
}
