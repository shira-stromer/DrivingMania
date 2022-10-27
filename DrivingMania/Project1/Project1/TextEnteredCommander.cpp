#include "TextEnteredCommander.h"
#include "GameScene.h"
#include "Controller.h"
#include "NameScene.h"
 
TextEnteredCommander::TextEnteredCommander()
{
}

void TextEnteredCommander::execute(const sf::Event & ev)
{
	NameScene* tempNameScene = dynamic_cast<NameScene*>(Controller::getInstance().getScene().get());

	if (tempNameScene)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			tempNameScene->deleteLast();
			return;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			return;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			tempNameScene->saveChanges();
			return;
		}

		auto key = static_cast<char>(ev.text.unicode);
		std::cout << "ASCII character typed: " << key << std::endl;
		tempNameScene->addKey(key);
		
	}
}


TextEnteredCommander::~TextEnteredCommander()
{
}
