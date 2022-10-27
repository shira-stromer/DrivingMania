#include "KeyReleasedCommander.h"
#include "GameScene.h"
#include "Player.h"
#include "Controller.h"

KeyReleasedCommander::KeyReleasedCommander()
{
}

void KeyReleasedCommander::execute(const sf::Event & eve)
{
	//GameScene* tempGameScene = dynamic_cast<GameScene*>(Controller::getInstance().getScene().get());

	if (Controller::getInstance().getSceneName() == getTypeName<GameScene>())
	{
		if (eve.key.code == sf::Keyboard::Space)
		{
			Player::getInstance().slowCar();
			std::cout << "Slowed car\n";
		}
	}
}


KeyReleasedCommander::~KeyReleasedCommander()
{
}
