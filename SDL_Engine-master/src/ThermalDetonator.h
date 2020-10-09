#pragma once
#ifndef __THERMAL_DETONATOR__
#define __THERMAL_DETONATOR__

#include "Sprite.h"


class ThermalDetonator : public Sprite
{
public:
	ThermalDetonator();
	~ThermalDetonator();

	// Life Cycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	void setDistance(float distance);
	void setAngle(float angle);
	void setSpeed(float speed);

	float getDistance();
	float getAngle();
	float getSpeed();

private:
	//Physics stuff
	float m_distance, m_angle, m_speed;
	glm::vec2 position = { 0,0 };
};

#endif /* defined (__THERMAL_DETONATOR__) */
