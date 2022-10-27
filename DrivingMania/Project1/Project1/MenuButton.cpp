#include "MenuButton.h"
#include "Controller.h"
#include "MenuScene.h"
#include "Player.h"

MenuButton::MenuButton(sf::Vector2f pos)
	:IClickable("MenuButton", pos, 80,80)
{
}

void MenuButton::onClicked()
{	
	auto& window = Screen::getInstance().getWindow();
	window.setView(window.getDefaultView());

	//GameScene* tempGameScene = dynamic_cast<GameScene*>(Controller::getInstance().getScene().get());
	if (Controller::getInstance().getSceneName() == getTypeName<GameScene>())
	{
		Player::getInstance().cleanUpInstance();
	}

	//TODO: Save the details from the game if came from game scene
	Controller::getInstance().setScene(std::make_unique<MenuScene>());
}


MenuButton::~MenuButton()
{
}

