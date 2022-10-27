#pragma once
#include "StaticComponent.h"

class Ground :
	public StaticComponent
{
public:
	Ground(std::string, sf::Vector2f, int, int);
	~Ground();
	void playSound()override;
	virtual void draw() override {}
};

