#pragma once
#include "ofMain.h"
#include <vector>
#include <random>
#include "Particle.h"

class ParticleData
{
public:
	size_t m_count = 0;
	size_t m_countAlive = 0;

    std::vector<Particle> particles;
	ParticleData() { }
	ParticleData(size_t maxCount) { generate(maxCount); }

	void generate(size_t maxSize);
	void kill(size_t id);
	void wake(size_t id);
	void swapData(size_t a, size_t b);
};

