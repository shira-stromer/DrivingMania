#include "DirectionKeyCommander.h"
#include "Player.h"
#include "Controller.h"
#include <algorithm>
#include "Utilities.h"


DirectionKeyCommander::DirectionKeyCommander() {}

void DirectionKeyCommander::execute(const sf::Event & eve)
{
	auto sceneName = Controller::getInstance().getSceneName();
	if(getTypeName<GameScene>() == sceneName)
	{
		Player::getInstance().move();
	}
}

DirectionKeyCommander::~DirectionKeyCommander() {}

