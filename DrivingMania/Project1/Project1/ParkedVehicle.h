#pragma once
#include "StaticComponent.h"
class ParkedVehicle :
	public StaticComponent
{
public:
	ParkedVehicle(std::string, sf::Vector2f, int, int);
	~ParkedVehicle();
	void rotate(float r);
	void playSound()override;
};

