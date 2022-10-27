#pragma once
#include "ICommand.h"
#include <memory>
#include <map>
#include <string>
#include "MouseClickedCommander.h"
#include "DirectionKeyCommander.h"

class CommandExecuter
	:public ICommand
{
public:
	CommandExecuter();
	virtual void execute(const sf::Event&) override;
	~CommandExecuter();

private:
	std::map<std::string, std::unique_ptr<ICommand>> m_commands;
	void initCommands();
};

