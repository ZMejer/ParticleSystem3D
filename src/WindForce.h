#pragma once
#include "ParticleData.h"

class WindForce
{
    public:
        bool isWindActive = false;
        void activateWind(float dt, ParticleData* p);
        float windStrength = 0.0;
};