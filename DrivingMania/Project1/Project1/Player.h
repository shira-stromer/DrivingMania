#include "GameComponent.h"
#include "NameScene.h"
#include "MovingComponent.h"
#include "GameOverScene.h"
#include "Animation.h"
#include <memory>
#include "AnimatedGameComponent.h"

#pragma once

class ComponentFactory;
class Controller;
class Player :public MovingComponent
{
public:
	static Player& getInstance();
	virtual void move() override;
	void cleanUpInstance();
	void setPlayerName(std::string pn);
	std::string getName();
	int getScore() const;
	void slowCar();
	void onCollision(std::string);
	void increaseScore(int amount);
	virtual void draw() override;
	void takeLife();
	bool isRecoveredFromCollision();
	int getLives() const;
	void setPosition(sf::Vector2f);
	void increaseLives(std::string sender);
	~Player();

private:
	Player();
	Player(const Player&);
	int m_score;
	int m_lives = LIVES_AMOUNT;
	std::string m_playerName;
	Timer m_timer;
	std::shared_ptr<AnimatedGameComponent> m_currentAnimation = NULL;
};

