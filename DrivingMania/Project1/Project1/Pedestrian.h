#pragma once
#include "MovingComponent.h"
#include "Utilities.h"
#include "Animation.h"
#include "RandomMove.h"

const int MIN_SPEED = 30;
const int MAX_SPEED = 50;
const float PEDESTRIAN_ANIMATION = 0.12f;

class Pedestrian :
	public MovingComponent
{
public:
	Pedestrian(std::string st, sf::Vector2f pos, int width, int height);
	~Pedestrian();
	virtual void move() override;
	void playSound()override;
	void revert()override;

private:
	Timer m_waitTimer;
	Animation m_animation;
	Timer m_timer;
};

