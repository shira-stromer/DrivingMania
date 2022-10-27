#pragma once
#include "ICommand.h"
#include "SFML\Graphics.hpp"


class MouseClickedCommander
	:public ICommand
{
public:
	MouseClickedCommander();
	virtual void execute(const sf::Event&) override;
	~MouseClickedCommander();
};

