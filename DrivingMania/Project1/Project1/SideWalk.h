#pragma once
#include "StaticComponent.h"
class SideWalk :
	public StaticComponent
{
public:
	SideWalk(std::string, sf::Vector2f, int, int);
	~SideWalk();
	void playSound()override;
	virtual void draw() override {}
};

