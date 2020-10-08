#include "ThermalDetonator.h"
#include "TextureManager.h"
#include "Util.h"

ThermalDetonator::ThermalDetonator()
{
	TextureManager::Instance()->load(
		"../Assets/sprites/detonator.png", "detonator");

	getTransform()->position = glm::vec2(30.0f, 500.f);
	getRigidBody()->velocity = glm::vec2(0, 0);

	const auto size = TextureManager::Instance()->getTextureSize("detonator");
	getRigidBody()->isColliding = false;
	setWidth(size.x);
	setHeight(size.y);

	//Flat Surface y AXIS = 500 !
	getTransform()->position = glm::vec2(90, 500.0f);
	getRigidBody()->velocity = glm::vec2(0, 0);
	getRigidBody()->acceleration = glm::vec2(0, 0);
	getRigidBody()->isColliding = false;

	m_angle = 0;

	setType(PLAYER);

}

ThermalDetonator::~ThermalDetonator()
{

}

void ThermalDetonator::clean()
{

}


void ThermalDetonator::setDistance(float distance)
{
	this->m_distance = distance;
}

void ThermalDetonator::setAngle(float angle)
{
	this->m_angle = Util::Deg2Rad * angle;
}

void ThermalDetonator::setSpeed(float speed)
{
	this->m_speed = speed;
	getRigidBody()->velocity.x = speed * cos(m_angle);
	//SDL throwing upwards is actually is reducing y-axis value.
	getRigidBody()->velocity.y = -speed * sin(m_angle);
}

float ThermalDetonator::getDistance()
{
	//pending
	return m_distance;
}

float ThermalDetonator::getAngle()
{
	//pending
	return m_angle;
}

float ThermalDetonator::getSpeed()
{
	//pending
	return m_speed;
}

void ThermalDetonator::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the target
	TextureManager::Instance()->draw("detonator", x, y, 0, 255, true);
}

void ThermalDetonator::update()
{
	//physics time

	//An object that gets thrown off with a velocity, gravity and at a certain angle,
	//will come to the that same x-axis level and at the same speed due to
	//the acceleration and deceleration that the object gets.
	//Hence the detonator lands at the stormtroopers the landing velocity is equal to the starting velocity
	//And when it lands, booom!

	if (getRigidBody()->velocity.y > m_speed * sin(m_angle))
	{
		//time to stop.
		position = { 0,0 };
	}
	else
	{
		position = getTransform()->position;
		//std::cout << "speed.y = " << getRigidBody()->velocity.y << std::endl;

		// better way to do??
		
		//replace 9.81 with gravity factor.
		//getRigidBody()->velocity.y += gravity * deltaTime;
		//getRigidBody()->velocity += (getRigidBody()->acceleration + gravity) * deltaTime;
		//position.y += getRigidBody()->velocity.y * deltaTime;
		//position.x += getRigidBody()->velocity.x * deltaTime;
		getTransform()->position = position;
	}

}

