#include "IClickable.h"


IClickable::IClickable(std::string name, sf::Vector2f position, int height, int width)
	:Component(name, position, width, height)
{
}

bool IClickable::isClicked(sf::Vector2f pos)
{
	return m_component.getGlobalBounds().contains(pos);
}


IClickable::~IClickable()
{
}
