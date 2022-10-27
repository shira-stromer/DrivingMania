#include "SoundButton.h"



SoundButton::SoundButton()
	:IClickable("SoundButton/SoundButton", sf::Vector2f(150, 850), 40, 40),
	m_animation("SoundButton", 40, 40, true)
{
}

void SoundButton::onClicked()
{
	auto& soundManager = SoundManager::getInstance();
	m_isOff = !m_isOff;
	
	if (m_isOff)
	{
		m_prevVolume = soundManager.getVolume();
		soundManager.turnMusicOff();
	}
	else
	{
		soundManager.turnMusicOn(m_prevVolume);
	}
	
	m_animation.setNextFrame(m_component);
}


SoundButton::~SoundButton()
{
}
