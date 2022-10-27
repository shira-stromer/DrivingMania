#pragma once
#include "StaticComponent.h"
#include "Constants.h"
#include "TimePassedHanlder.h"
#include "INotifiable.h"

class TrafficLight
	:public StaticComponent, public INotifiable
{
public:
	TrafficLight(std::string name, sf::Vector2f pos, int height, int width);
	~TrafficLight();
	virtual void onNotify(std::string sender) override;
	bool isRed();
	bool isPassed();
	void pass();


private:
	TrafficLightColor m_lightColor;
	Timer m_timer;
	TrafficLightColor changeColor();
	void colorComponent();
	bool m_passed = false;
};

