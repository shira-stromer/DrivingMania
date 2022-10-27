#pragma once
#include "MovingComponent.h"
#include "RandomMove.h"

class MovingVehicle :
	public MovingComponent
{
public:
	MovingVehicle(std::string str, sf::Vector2f pos, int width, int height);
	~MovingVehicle();
	virtual void move() override;
	virtual void revert() override;
	virtual void saveValidPosition() override;
	void cleanUpInstance();
	virtual bool isMoveValid() override;
	virtual void playSound() override;

private:
	Timer m_waitTimer;
	sf::Vector2f m_initializedPosition;
	bool m_colideFlag = false;
};


