#pragma once
#include "StaticComponent.h"
#include "TrafficLight.h"
#include <memory>
#include "CrossWalkBase.h"

class CrossWalk :
	public CrossWalkBase
{
public:
	CrossWalk(std::string name, sf::Vector2f pos, int height, int width);
	~CrossWalk();
};

