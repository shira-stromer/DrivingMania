#pragma once
#include "SFML\Graphics.hpp"

class IColisionable
{
public:
	IColisionable();
	virtual ~IColisionable();
	virtual bool colide(sf::RectangleShape component) = 0;

};

