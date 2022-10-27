#pragma once
#include <SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "IDrawable.h"
#include "Screen.h"
#include "IMovable.h"

class Component
	:public IDrawable
{
public:
	Component();
	Component(std::string name, sf::Vector2f, int width, int height);
	~Component();
	sf::Vector2f getPosition();
	float getRotation();
	virtual void draw() override;

protected:
	sf::RectangleShape m_component;
};

