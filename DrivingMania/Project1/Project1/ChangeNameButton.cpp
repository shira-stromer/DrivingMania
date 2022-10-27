#include "ChangeNameButton.h"
#include "Controller.h"


ChangeNameButton::ChangeNameButton()
	:IClickable("ChangeNameButton", sf::Vector2f(651,443), 89 ,200)
{
}

void ChangeNameButton::onClicked()
{
	Controller::getInstance().setScene(std::make_unique<NameScene>());
}


ChangeNameButton::~ChangeNameButton()
{
}
