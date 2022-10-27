#pragma once
#include "SFML\Graphics.hpp"
#include "Component.h"

class IClickable
	:public Component
{
public:
	IClickable(std::string name, sf::Vector2f position, int height, int width);
	virtual bool isClicked(sf::Vector2f);
	virtual void onClicked() = 0;
    ~IClickable();
};
