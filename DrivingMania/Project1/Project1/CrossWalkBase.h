#pragma once
#include "StaticComponent.h"
class CrossWalkBase
	:public StaticComponent
{
public:
	CrossWalkBase(std::string name, sf::Vector2f pos, int height, int width);
	~CrossWalkBase();
};

