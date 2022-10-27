#include "MovingVehicle.h"
#include "StrightMove.h"


MovingVehicle::MovingVehicle(std::string str, sf::Vector2f pos, int height, int width) 
	:MovingComponent(str, pos, width, height), m_initializedPosition(pos)
{
	m_speed = getRandom(20, 50);
	if (pos.x < 50)
	{
		m_component.rotate(Right);
		m_component.move(0, width);
	}
	else
	{
		m_component.rotate(Left);
		m_component.move(0, width);
	}

	m_move = std::make_unique<StrightMove>(*this);
	m_waitTimer.setTimerFor(getRandom(0, 3));
}


MovingVehicle::~MovingVehicle()
{
}

void MovingVehicle::move()
{
	if (!m_colideFlag)
		saveValidPosition();

	m_colideFlag = false;
	m_move->move();
}

void MovingVehicle::revert()
{
	if (m_waitTimer.isTimePassed())
	{
		m_waitTimer.setTimerFor(getRandom(0, 2));
	}
	m_colideFlag = true;
	m_component.setPosition(m_lastPosition);
	randomizeDirection(m_direction);
}

void MovingVehicle::saveValidPosition()
{
	if (m_waitTimer.isTimePassed())
		MovingComponent::saveValidPosition();
}

void MovingVehicle::cleanUpInstance()
{
	m_component.setPosition(m_initializedPosition);
}

bool MovingVehicle::isMoveValid()
{
	return m_waitTimer.isTimePassed();
}

void MovingVehicle::playSound()
{
	SoundManager::getInstance().playCollision("MovingCarSound");
}
