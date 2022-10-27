#include "Screen.h"



Screen::Screen()
	:m_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "DrivingMania")
{
	setIcon();
}

void Screen::setIcon()
{
	sf::Image icon;
	if (!icon.loadFromFile("Images/Icon.png"))
	{
		throw std::exception("Icon could not be loaded");
	}

	m_window.setIcon(148, 137, icon.getPixelsPtr());
}


Screen & Screen::getInstance()
{
	static Screen m_instance;
	return m_instance;
}

sf::RenderWindow & Screen::getWindow()
{
	return m_window;
}

void Screen::changeToDefaultView()
{
	m_window.setView(m_window.getDefaultView());
}

Screen::~Screen()
{
}
