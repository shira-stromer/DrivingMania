#include "RandomMove.h"
#include "Player.h"


RandomMove::RandomMove(MovingComponent& mvcmp)
	:m_component(mvcmp), m_direction(mvcmp.getDirection())
{
	m_rotate.setTimerFor(ROTATE_SECONDS);
}


RandomMove::~RandomMove()
{
}

void RandomMove::move()
{
	if (!m_component.isMoveValid())
	{
		m_clock.restart();
		return;
	}

	if (m_rotate.isTimePassed())
	{
		if (m_rotate.m_seconds == ROTATE_SECONDS)
		{
			if (m_component.getRotation() != m_direction)
			{
				m_component.rotate(ROTATE_AMOUNT);
				if (m_component.getRotation() != m_direction)
				{
					m_rotate.setTimerFor(ROTATE_SECONDS);
				}
			
				//std::cout << "rotating" << std::endl;
				return;
			}

			//std::cout << "start walking" << std::endl;
			m_rotate.setTimerFor(getRandom(MOVE_MIN, MOVE_MAX));
			m_clock.restart();
		}
		else
		{
			//TODO: set new direction
			auto oldDirection = m_direction;
			randomizeDirection(m_direction);
			if (m_direction != oldDirection)
			{
				m_rotate.setTimerFor(ROTATE_SECONDS);
			}
			else
			{
				m_rotate.setTimerFor(getRandom(MOVE_MIN, MOVE_MAX));
			}
			//std::cout << "need to change to new direction" << std::endl;
		}
	}
	else
	{
		if (m_rotate.m_seconds != ROTATE_SECONDS)
		{
			sf::Transform t;
			t.rotate(m_component.getComponent().getRotation());
			auto movementVec = t.transformPoint(FORWARD_VEC);
			m_component.move(movementVec * m_component.getSpeed() *m_clock.restart().asSeconds());
		}
	}
}

void RandomMove::move(sf::Vector2f)
{
}
