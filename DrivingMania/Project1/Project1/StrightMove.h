#pragma once
#include "MovingComponent.h"
#include "IMovable.h"
#include "SFML\Graphics.hpp"

class StrightMove :
	public IMovable
{
public:
	StrightMove(MovingComponent& mvcmp);
	~StrightMove();
	virtual void move() override;
	virtual void move(sf::Vector2f) override {}

private:
	sf::Clock m_clock;
	MovingComponent & m_component;

};

