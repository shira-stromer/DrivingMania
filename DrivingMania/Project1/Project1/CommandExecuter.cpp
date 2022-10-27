#include "CommandExecuter.h"
#include "TextEnteredCommander.h"
#include "KeyReleasedCommander.h"

CommandExecuter::CommandExecuter()
{
	initCommands();
}

void CommandExecuter::execute(const sf::Event& eve)
{
	switch (eve.type)
	{
	case sf::Event::EventType::MouseButtonPressed:
		m_commands["MouseClicked"]->execute(eve);
		return;
	case sf::Event::EventType::KeyPressed:
		m_commands["KeyPressed"]->execute(eve);
		return;
	case sf::Event::TextEntered:
 		m_commands["TextEntered"]->execute(eve);
		return;
	case sf::Event::KeyReleased:
		m_commands["KeyReleased"]->execute(eve);
		return;
	default:
		break;
	}
}


CommandExecuter::~CommandExecuter()
{
}

void CommandExecuter::initCommands()
{
	m_commands["MouseClicked"] = std::make_unique<MouseClickedCommander>();
	m_commands["KeyPressed"] = std::make_unique<DirectionKeyCommander>();
	m_commands["TextEntered"] = std::make_unique<TextEnteredCommander>();
	m_commands["KeyReleased"] = std::make_unique<KeyReleasedCommander>();
}
