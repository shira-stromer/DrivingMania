#include "StartGameButton.h"
#include "Controller.h"


StartGameButton::StartGameButton()
	:IClickable("StartButton", sf::Vector2f(651,243), 89, 200)
{
}

void StartGameButton::onClicked()
{
	std::cout << "Start Game Button Clicked" << std::endl;
	Controller::getInstance().setScene(std::make_unique<GameScene>());
}


StartGameButton::~StartGameButton()
{
}
