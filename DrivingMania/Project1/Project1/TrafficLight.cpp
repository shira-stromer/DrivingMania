#include "TrafficLight.h"
#include "Controller.h"
#include "Utilities.h"

TrafficLight::TrafficLight(std::string name,  sf::Vector2f pos, int height, int width)
	:StaticComponent(name, pos, height, width)
{
	auto num = getRandom(1, 3);
	switch (num)
	{
	case 1:
		m_lightColor = Red;
		break;
	case 2:
		m_lightColor = Yellow;
		break;
	case 3:
		m_lightColor = Green;
		break;
	default:
		m_lightColor = Red;
		break;
	}
	m_timer.setTimerFor((float)m_lightColor);
}

TrafficLight::~TrafficLight()
{
}

void TrafficLight::onNotify(std::string sender)
{
	if (sender == getTypeName<TimePassedHanlder>())
	{
		changeColor();
		colorComponent();
	}
}

bool TrafficLight::isRed()
{
	return m_lightColor == Red;
}

bool TrafficLight::isPassed()
{
	return m_passed;
}

void TrafficLight::pass()
{
	m_passed = true;
}

TrafficLightColor TrafficLight::changeColor()
{
	if (m_timer.isTimePassed())
	{
		switch (m_lightColor)
		{
		case Red:
			m_lightColor = Yellow;
			break;
		case Yellow:
			m_lightColor = Green;
			break;
		case Green:
			m_lightColor = Red;
			break;
		}
		m_timer.setTimerFor((float)m_lightColor);
		m_passed = false;
	}
	return m_lightColor;
}

void TrafficLight::colorComponent()
{
	switch (m_lightColor)
	{
	case Red:
		m_component.setFillColor(sf::Color::Red);
		break;
	case Yellow:
		m_component.setFillColor(sf::Color::Yellow);
		break;
	case Green:
		m_component.setFillColor(sf::Color::Green);
		break;
	default:
		break;
	}
}
