#pragma once
#include "IColisionable.h"
#include "SFML\Graphics.hpp"

class Collisionable :
	public IColisionable
{
public:
	Collisionable(sf::RectangleShape& component);
	virtual bool colide(sf::RectangleShape component) override;
	~Collisionable();

private:
	sf::RectangleShape& m_component;
};

