#include "ExitButton.h"



ExitButton::ExitButton()
	:IClickable("ExitButton", sf::Vector2f(651, 643), 89, 200)
{
}

void ExitButton::onClicked()
{
	exit(EXIT_SUCCESS);
}


ExitButton::~ExitButton()
{
}
