#include "StaticComponent.h"

StaticComponent::StaticComponent(std::string type , sf::Vector2f pos, int height, int width)
	:GameComponent(type, pos, height, width)
{
}


StaticComponent::~StaticComponent()
{
}
