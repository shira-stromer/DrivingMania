#pragma once
#include "IClickable.h"
#include "HelpScene.h"

class Controller;
class HelpButton :
	public IClickable
{
public:
	HelpButton(std::string, sf::Vector2f pos, int width, int height);
	~HelpButton();
	virtual void onClicked() override;
};