#include "ParticleUpdater.h"
#include "glm/gtc/random.hpp"
#include "ofMain.h"
#include "WindForce.h"

void ParticleUpdater::update(float dt, ParticleData* p, float sphereRadius, bool isWindActive)
{
	const unsigned int endId = p->m_countAlive;
	for (size_t i = 0; i < endId; ++i) {
		p->particles[i].m_vel += dt * p->particles[i].m_acc;
		p->particles[i].m_pos += dt * p->particles[i].m_vel;
		p->particles[i].m_TimeAlive += dt;
        /*
		if (p->particles[i].m_TimeAlive >= p->particles[i].m_maxTimeAlive) {
			p->kill(i);
		}
        */
       if (p->particles[i].m_pos.y < -50){
            p->particles[i].m_pos = glm::vec3(ofRandom(-50,50),300,ofRandom(-50,50));
            p->particles[i].m_vel = glm::vec3(ofRandom(-10,10),ofRandom(-10,10),ofRandom(-10,10));
            
       }
       WindForce windforce;
       if (isWindActive) {
            windforce.windStrength = 0.001;
            windforce.activateWind(dt, p);
       }
       glm::vec3 sphereCenter = glm::vec3(0,0,0);
       float distance = glm::length (p->particles[i].m_pos - sphereCenter);
       if (distance < sphereRadius)
       {
            glm::vec3 direction = glm::normalize (p->particles[i].m_pos - sphereCenter);
            p->particles[i].m_pos = (sphereCenter + direction * sphereRadius);
            glm::vec3 velocity = p->particles[i].m_vel;
            glm::vec3 normal = glm::normalize (p->particles[i].m_pos - sphereCenter);
            glm::vec3 reflectedVelocity = velocity - 2.0f * glm::dot (velocity, normal) * normal;
            p->particles[i].m_vel = (reflectedVelocity * 0.8f);
       }
	}
}
