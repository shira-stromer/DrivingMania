#pragma once
#include "Constants.h"
#include "SFML\Graphics.hpp"

class ICommand
{
public:
	ICommand();
	virtual void execute(const sf::Event&) = 0;
	~ICommand();
};

