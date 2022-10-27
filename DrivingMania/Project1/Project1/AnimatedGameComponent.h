#pragma once
#include "GameComponent.h"
#include "Animation.h"
#include "StaticComponent.h"

class AnimatedGameComponent :
	public StaticComponent
{
public:
	AnimatedGameComponent(std::string str, sf::Vector2f pos, int width, int height, float animationSeconds, bool repeate);
	~AnimatedGameComponent();
	void startAnimation();
	void onTimePassed();

private:
	Timer m_timer;
	Animation m_animation;
	float m_seconds;
};

