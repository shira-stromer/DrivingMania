#pragma once
#include "GameComponent.h"
#include "Collisionable.h"
#include <memory>

class StaticComponent :
	public GameComponent
{
public:
	StaticComponent(std::string, sf::Vector2f, int, int);
	~StaticComponent();
};											