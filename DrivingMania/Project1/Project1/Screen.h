#pragma once
#include <SFML\Graphics.hpp>
#include "Constants.h"

class Screen
{
public:
	static Screen& getInstance();
	sf::RenderWindow& getWindow();
	void changeToDefaultView();
	~Screen();

private:
	Screen();
	void setIcon();
	Screen(const Screen&);
	sf::RenderWindow m_window;
};

