#pragma once
#include "IMovable.h"
#include "SFML\Graphics.hpp"
#include "MovingComponent.h"
#include "Constants.h"
#include "Utilities.h"

const float ROTATE_SECONDS = 0.5f;
const int MOVE_MIN = 8;
const int MOVE_MAX = 15;
const int ROTATE_AMOUNT = 15; //Notice must be devided 
const sf::Vector2f FORWARD_VEC(0.f, 1.f);

class RandomMove :
	public IMovable
{
public:
	RandomMove(MovingComponent& mvcmp);
	~RandomMove();
	virtual void move() override;
	virtual void move(sf::Vector2f) override;

private:
	MovingComponent & m_component;
	Timer m_rotate;
	sf::Clock m_clock;
	Direction& m_direction;
};

