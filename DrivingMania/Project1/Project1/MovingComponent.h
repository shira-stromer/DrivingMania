#pragma once
#include "IMovable.h"
#include "GameComponent.h"
class MovingComponent :
	public GameComponent
{
public:
	MovingComponent(std::string, sf::Vector2f, int, int);
	~MovingComponent();
	sf::Vector2f getPosition();
	void rotate(float);
	virtual void move() override;
	float getSpeed();
	virtual void move(sf::Vector2f) override;
	virtual void saveValidPosition();
	virtual void revert();
	Direction& getDirection();
	virtual bool isMoveValid();

protected:
	sf::Vector2f m_lastPosition;
	float m_rotation;
	Direction m_direction;
	float m_speed = 50.f;
	sf::Clock m_clock;
	Timer m_rotateTimer;
	sf::Vector2f m_initialPosition;
};

