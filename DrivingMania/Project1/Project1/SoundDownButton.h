#pragma once
#include <string>
#include "SFML\Graphics.hpp"
#include "IClickable.h"
#include <iostream>
#include "SoundManager.h"

class SoundDownButton
	:public IClickable
{
public:
	SoundDownButton(sf::Vector2f position, int height, int width);
	virtual void onClicked() override;
	~SoundDownButton();
};