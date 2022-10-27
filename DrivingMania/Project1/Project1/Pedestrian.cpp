#include "Pedestrian.h"


Pedestrian::Pedestrian(std::string st, sf::Vector2f pos, int width, int height)
	:MovingComponent(st + "/" + st, pos, width, height), m_animation(st, width, height)
{
	m_speed = getRandom(MIN_SPEED, MAX_SPEED);
	m_timer.setTimerFor(PEDESTRIAN_ANIMATION);
	m_move = std::make_unique<RandomMove>(*this);
	m_waitTimer.setTimerFor(0); //Critical
}

Pedestrian::~Pedestrian() {}

void Pedestrian::move()
{
	if (m_timer.isTimePassed())
	{
		m_animation.setNextFrame(m_component);
		m_timer.onTimePassed();
	}

	if (m_waitTimer.isTimePassed())
	{
		m_move->move();
	}
}


void Pedestrian::playSound()
{
	SoundManager::getInstance().playCollision("HitPadestrian");
}

void Pedestrian::revert()
{
	if (m_waitTimer.isTimePassed())
	{
		m_waitTimer.setTimerFor(getRandom(0, 2));
	}

	randomizeDirection(m_direction);
}
