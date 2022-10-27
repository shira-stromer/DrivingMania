#pragma once
#include "IClickable.h"
#include "SFML\Graphics.hpp"
#include "IMovable.h"

class Controller;
class MenuButton :
	public IClickable
{
public:
	MenuButton(sf::Vector2f = sf::Vector2f());
	virtual void onClicked() override;
	~MenuButton();
};

