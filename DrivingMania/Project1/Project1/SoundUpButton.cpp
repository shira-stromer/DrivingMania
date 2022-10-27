#include "SoundUpButton.h"


SoundUpButton::SoundUpButton(sf::Vector2f position, int height, int width)
	:IClickable("SoundUpButton", position, height, width)
{
}

void SoundUpButton::onClicked()
{
	std::cout  <<"sound up button clicked" << std::endl;
	SoundManager::getInstance().increaseVolume();
}

SoundUpButton::~SoundUpButton()
{
}
