#include "MovingComponent.h"


MovingComponent::MovingComponent(std::string name, sf::Vector2f position, int width, int height):
	GameComponent(name, position, width, height), m_direction(Top), m_initialPosition(position)
{
}


MovingComponent::~MovingComponent()
{
}

sf::Vector2f MovingComponent::getPosition()
{
	return m_component.getPosition();
}

void MovingComponent::rotate(float r)
{
	m_component.rotate(r);
}

void MovingComponent::move()
{

}

float MovingComponent::getSpeed()
{
	return m_speed;
}

void MovingComponent::move(sf::Vector2f pos)
{
	m_component.move(pos);
}

void MovingComponent::saveValidPosition()
{
	m_lastPosition = getPosition();
	m_rotation = m_component.getRotation();
}

void MovingComponent::revert()
{
	m_component.setPosition(m_lastPosition);
	m_component.setRotation(m_rotation);
	m_clock.restart();
	m_speed = 0;
}

Direction & MovingComponent::getDirection()
{
	return m_direction;
}

bool MovingComponent::isMoveValid()
{
	return true;
}
