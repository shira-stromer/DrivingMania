#include "SoundDownButton.h"



SoundDownButton::SoundDownButton(sf::Vector2f position, int height, int width)
	:IClickable("SoundDownButton", position, height, width)
{
}

void SoundDownButton::onClicked()
{
	std::cout << "sound down button clicked" << std::endl;
	SoundManager::getInstance().decreaseVolume();
}


SoundDownButton::~SoundDownButton()
{
}
