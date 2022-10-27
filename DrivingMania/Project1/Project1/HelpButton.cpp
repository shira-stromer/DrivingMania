#include "HelpButton.h"
#include "Controller.h"


HelpButton::HelpButton(std::string str, sf::Vector2f pos, int width, int height)
	:IClickable(str, pos, width,height)
{
}


HelpButton::~HelpButton()
{
}

void HelpButton::onClicked()
{
	Controller::getInstance().setScene(std::make_unique<HelpScene>());
}
