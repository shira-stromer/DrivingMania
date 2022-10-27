#pragma once
#include "StaticComponent.h"
#include "AnimatedGameComponent.h"

class Player;
class Coin
	:public AnimatedGameComponent
{
public:
	Coin(std::string, sf::Vector2f pos, int width, int height);
	~Coin();
	int getScore();
	void playSound()override;
};

