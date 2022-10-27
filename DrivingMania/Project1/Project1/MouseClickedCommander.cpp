#include "MouseClickedCommander.h"
#include "Controller.h"
#include <algorithm>

MouseClickedCommander::MouseClickedCommander()
{
}

void MouseClickedCommander::execute(const sf::Event & eve)
{
	auto buttons = Controller::getInstance().getScene()->getButtons();
	
	auto mousePos = sf::Vector2f((float)eve.mouseButton.x, (float)eve.mouseButton.y);
	std::cout << "Mouse Clicked on: (" << mousePos.x << "," << mousePos.y << ")" << std::endl;

	std::for_each(buttons.begin(), buttons.end(), [mousePos](std::shared_ptr<IClickable> button) 
	{
		if (button->isClicked(mousePos))
		{
			button->onClicked();
		}
	});
}


MouseClickedCommander::~MouseClickedCommander()
{
}
