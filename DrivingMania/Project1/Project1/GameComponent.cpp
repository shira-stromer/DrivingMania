#include "GameComponent.h"
#include <memory>
#include "Collisionable.h"


GameComponent::GameComponent()
{
}

GameComponent::GameComponent(std::string name, sf::Vector2f position, int width, int height) :
	Component(name, position, width, height)
{
	m_colide = std::make_unique<Collisionable>(m_component);
	//m_move = NULL;
}


GameComponent::~GameComponent()
{
}

sf::Vector2f GameComponent::getPosition()
{
	return m_component.getPosition();
}

bool GameComponent::colide(sf::RectangleShape comp)
{
	if (m_colide == NULL)
		return false;

	return m_colide->colide(comp);
}

void GameComponent::move()
{
	if (m_move != NULL)
		m_move->move();
}

void GameComponent::move(sf::Vector2f f)
{
	m_component.move(f);
}

void GameComponent::hide()
{
	m_component.setScale(sf::Vector2f());
}



sf::RectangleShape GameComponent::getComponent()
{
	return m_component;
}
