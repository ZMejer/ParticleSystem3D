#include "ParticleData.h"

void ParticleData::generate(size_t maxSize)
{
	m_count = maxSize;
	m_countAlive = 0;

    while (maxSize-- > 0) {

        glm::vec3 velocity = glm::vec3(ofRandom(-10,10),ofRandom(-10,10),ofRandom(-10,10));
        //glm::vec3 acceleration = glm::vec3(ofRandom(-3,3),ofRandom(-3,3),ofRandom(-3,3));
        glm::vec3 acceleration = glm::vec3(0, -9.8f, 0);
        //glm::vec3 acceleration = glm::vec3(0, 0, 0);
        glm::vec3 color = glm::vec3(219,ofRandom(0,255),196);
        glm::vec3 position = glm::vec3(ofRandom(-50,50),300,ofRandom(-50,50));
        Particle p(velocity, acceleration, color, position);
        particles.push_back(p);
        m_countAlive ++;
    }
}

void ParticleData::kill(size_t id)
{
    if (m_countAlive > 0)
    {
        particles[id].m_alive = false;
        swapData(id, m_countAlive - 1);
        m_countAlive--;
    }
}

void ParticleData::wake(size_t id)
{
    if (m_countAlive < m_count)
    {
        particles[id].m_alive = true;
        swapData(id, m_countAlive);
        m_countAlive++;
    }
}

void ParticleData::swapData(size_t idA, size_t idB)
{
    std::swap(particles[idA], particles[idB]);
}