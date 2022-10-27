#include "ScoresButton.h"
#include "Controller.h"


ScoresButton::ScoresButton()
	:IClickable("ScoreButton", sf::Vector2f(651,343), 89, 200)
{
}

void ScoresButton::onClicked()
{
	Controller::getInstance().setScene(std::make_unique<ScoresScene>());
}

ScoresButton::~ScoresButton()
{
}
