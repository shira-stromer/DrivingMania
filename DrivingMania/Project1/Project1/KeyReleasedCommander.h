#pragma once
#include "ICommand.h"
#include "SFML\Graphics.hpp"

class KeyReleasedCommander :
	public ICommand
{
public:
	KeyReleasedCommander();
	virtual void execute(const sf::Event&) override;
	~KeyReleasedCommander();
};

