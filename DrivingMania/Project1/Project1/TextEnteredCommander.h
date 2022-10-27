#pragma once
#include "ICommand.h"
class TextEnteredCommander :
	public ICommand
{
public:
	TextEnteredCommander();
	virtual void execute(const sf::Event&) override;
	~TextEnteredCommander();
};

