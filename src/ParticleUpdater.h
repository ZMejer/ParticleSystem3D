#pragma once
#include "ParticleData.h"

class ParticleUpdater
{
public:
	ParticleUpdater() { }
	virtual ~ParticleUpdater() { }
	virtual void update(float dt, ParticleData* p, float sphereRadius, bool isWindActive);
};