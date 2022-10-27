#include "AnimatedGameComponent.h"
#include "Utilities.h"


AnimatedGameComponent::AnimatedGameComponent(std::string str,sf::Vector2f pos, int width, int height, float animationSeconds, bool repeate)
	:StaticComponent(str+ "/" + str, pos, width, height),
	m_animation(str, width, height, repeate),
	m_seconds(animationSeconds)
{
	m_timer.m_on = false;
}


AnimatedGameComponent::~AnimatedGameComponent()
{
}

void AnimatedGameComponent::startAnimation()
{
	m_timer.setTimerFor(m_seconds);
}

void AnimatedGameComponent::onTimePassed()
{
	if (m_timer.isTimePassed())
	{
		m_animation.setNextFrame(m_component);
		if (m_component.getScale() == sf::Vector2f())
		{
			m_timer.m_on = false;
			return;
		}
		m_timer.onTimePassed();
	}
}
