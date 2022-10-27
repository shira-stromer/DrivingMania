#include "Arrow.h"
#include "Player.h"

Arrow::Arrow(std::string st, sf::Vector2f pos, int width, int height)
	:StaticComponent(st, pos, width, height)
{
	m_component.setFillColor(UNCOMPLETE_ARROW_COLOR);
}

Arrow::~Arrow()
{
}

void Arrow::completeState()
{
	m_complete = true;
	m_component.setFillColor(COMPLETE_ARROW_COLOR);
	Player::getInstance().increaseScore(getRandom(5, 15));
}

bool Arrow::isComplete() const
{
	return m_complete;
}

void Arrow::playSound()
{
	SoundManager::getInstance().playCollision("HitArrow");
}
