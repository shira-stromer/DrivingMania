#pragma once
#include <string>
#include "SFML\Graphics.hpp"
#include "IClickable.h"
#include <iostream>
#include "SoundManager.h"
#include <iostream>

class SoundUpButton
	:public IClickable
{
public:
	SoundUpButton(sf::Vector2f position, int height, int width);
	virtual void onClicked() override;
	~SoundUpButton();
};

