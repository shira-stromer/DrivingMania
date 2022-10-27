#include "ParkedVehicle.h"




ParkedVehicle::ParkedVehicle(std::string x, sf::Vector2f y, int h, int w) :StaticComponent(x, y, h, w)
{
}


ParkedVehicle::~ParkedVehicle()
{
}

void ParkedVehicle::rotate(float r)
{
	m_component.rotate(r);
}

void ParkedVehicle::playSound()
{
	SoundManager::getInstance().playCollision("HitParkedCar");
}
