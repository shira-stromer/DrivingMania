#include "IColisionable.h"
#include "Component.h"
#include <memory>
#include "IColisionable.h"
#include "IMovable.h"
#include "SFML\Graphics.hpp"
#include "SoundManager.h"

#pragma once

class GameComponent :
	public Component, public IColisionable, public IMovable
{
public:
	GameComponent();
	GameComponent(std::string, sf::Vector2f, int, int);
	~GameComponent();
	sf::Vector2f getPosition();
	virtual bool colide(sf::RectangleShape comp) override;
	sf::RectangleShape getComponent();
	virtual void move() override;
	virtual void move(sf::Vector2f) override;
	virtual void playSound() {};
	void hide();

protected:
	std::unique_ptr<IColisionable> m_colide;
	std::unique_ptr<IMovable> m_move;
};

