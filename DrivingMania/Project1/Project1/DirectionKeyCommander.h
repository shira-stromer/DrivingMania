#pragma once
#include "ICommand.h"

class Player;
class DirectionKeyCommander :
	public ICommand
{
public:
	DirectionKeyCommander();
	virtual void execute(const sf::Event&) override;
	~DirectionKeyCommander();
	
};

