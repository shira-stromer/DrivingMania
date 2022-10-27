#pragma once
#include "StaticComponent.h"
#include "SFML\Graphics.hpp"
#include "Constants.h"

class Arrow
	:public StaticComponent
{
public:
	Arrow(std::string st, sf::Vector2f pos, int width, int height);
	~Arrow();
	void completeState();
	bool isComplete() const;
	void playSound()override;
private:
	bool m_complete = false;

};

