#include "WindForce.h"

void WindForce::activateWind(float dt, ParticleData* p) {
    const unsigned int endId = p->m_countAlive;
    for (size_t i = 0; i < endId; ++i) {
        p->particles[i].m_vel.x += dt * windStrength;
    }
}