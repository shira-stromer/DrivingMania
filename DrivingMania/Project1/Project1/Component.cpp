#include "Component.h"



Component::Component()
{
}

Component::Component(std::string name,  sf::Vector2f pos, int width, int height)
{
	m_component = ResourceManager::getInstance().getValue<sf::RectangleShape>(name);
	m_component.setSize(sf::Vector2f((float)width, (float)height));
	m_component.setPosition(pos);
}


Component::~Component()
{
}

sf::Vector2f Component::getPosition()
{
	return m_component.getPosition();
}

float Component::getRotation()
{
	return m_component.getRotation();
}

void Component::draw()
{
	Screen::getInstance().getWindow().draw(m_component);
}
