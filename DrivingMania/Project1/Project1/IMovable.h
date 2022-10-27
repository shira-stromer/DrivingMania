#pragma once
#include <SFML\Graphics.hpp>

class IMovable
{
public:
	IMovable();
	virtual void move() = 0;
	virtual void move(sf::Vector2f) = 0;
	virtual ~IMovable();
};

