#include "Ground.h"



Ground::Ground(std::string str, sf::Vector2f pos, int height, int width)
	:StaticComponent(str, pos, height, width) {}


Ground::~Ground() {}

void Ground::playSound()
{
	SoundManager::getInstance().playCollision("HitGround");
}
