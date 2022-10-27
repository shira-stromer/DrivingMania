#include "StrightMove.h"
#include "Constants.h"


StrightMove::StrightMove(MovingComponent& cmvp)
	:m_component(cmvp)
{
}


StrightMove::~StrightMove()
{
}

void StrightMove::move()
{
	if (!m_component.isMoveValid())
	{
		m_clock.restart();
		return;
	}

	sf::Transform t;
	t.rotate(m_component.getComponent().getRotation());
	auto movementVec = t.transformPoint(-sf::Vector2f(0.f, 1.f));
	m_component.move(movementVec * m_component.getSpeed() *m_clock.restart().asSeconds());
}
