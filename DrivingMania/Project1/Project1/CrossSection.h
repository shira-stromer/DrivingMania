#pragma once
#include "CrossWalkBase.h"
#include <memory>
#include "TrafficLight.h"

class GameScene;
class Controller;
class CrossSection
	:public CrossWalkBase
{
public:
	CrossSection(std::string name, std::string trafficName, sf::Vector2f pos, int height, int width);
	~CrossSection();
	virtual void draw() override;
	std::shared_ptr<TrafficLight>& getTrafficLight();
	void playSound()override;
private:
	std::shared_ptr<TrafficLight> m_trafficLight;
};

