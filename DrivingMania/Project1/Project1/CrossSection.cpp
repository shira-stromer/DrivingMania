#include "CrossSection.h"
#include "GameScene.h"
#include "Controller.h"




CrossSection::CrossSection(std::string name, std::string trafficName, sf::Vector2f pos, int height, int width)
	:CrossWalkBase(name, pos, height, width), 
	m_trafficLight(std::make_shared<TrafficLight>( trafficName, sf::Vector2f(pos.x + (width/2), pos.y + (height/4)), height/3, width/3))
{
	Controller::getInstance().getTimePassedHandler()->registerForNotification(m_trafficLight);
}

CrossSection::~CrossSection()
{
}

void CrossSection::draw()
{
	CrossWalkBase::draw();
	m_trafficLight->draw();
}

std::shared_ptr<TrafficLight>& CrossSection::getTrafficLight()
{
	return m_trafficLight;
}

void CrossSection::playSound()
{
	SoundManager::getInstance().playCollision("HitCrossSection");
}
