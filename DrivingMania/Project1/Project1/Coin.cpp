#include "Coin.h"
#include "Player.h"

Coin::Coin(std::string st, sf::Vector2f pos, int width, int height)
	:AnimatedGameComponent(st, pos, width, height, 0.1f, true) {}

Coin::~Coin()
{
}

int Coin::getScore()
{
	m_component.setScale(sf::Vector2f());
	Player::getInstance().increaseLives(getTypeName<Coin>());
	playSound();
	return 50;
}

void Coin::playSound()
{
	SoundManager::getInstance().playCollision("HitCoin");
}

