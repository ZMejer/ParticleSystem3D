#pragma once
#include "ofMain.h"
class Particle
{
public: 
	bool m_alive = true;
	float m_TimeAlive { 0 };
	float m_maxTimeAlive { 10 };
	float mass = 1;


    glm::vec3 m_vel;
    glm::vec3 m_acc;
    glm::vec3 m_col;
    glm::vec3 m_pos;

	void update(float deltaTime);
	void render();

	Particle(){}
	Particle(glm::vec3 vel, glm::vec3 acc, glm::vec3 col, glm::vec3 pos) : m_vel(vel), m_acc(acc), m_col(col), m_pos(pos) {}
};

