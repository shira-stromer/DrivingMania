#include "SideWalk.h"




SideWalk::SideWalk(std::string x, sf::Vector2f y, int h, int w) :StaticComponent(x, y, h, w)
{
}

SideWalk::~SideWalk()
{
}

void SideWalk::playSound()
{
	SoundManager::getInstance().playCollision("HitSideWalk");
}
