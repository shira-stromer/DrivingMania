#include "Player.h"
#include "Controller.h"
#include "TimePassedHanlder.h"
#define _USE_MATH_DEFINES
#include "Controller.h"
#include <math.h>
#include "MovingComponent.h"
#include <algorithm>
#include "MenuScene.h"
#include <SFML\Graphics.hpp>
#include "TimePassedHanlder.h"
#include "ComponentFactory.h"


//some movement values
sf::Vector2f movementVec; //normal vector based on current direction
const sf::Vector2f forwardVec(0.f, 1.f); //normal vec pointing forward
//consts are units per second as each value is multiplied by frame time
const float acceleration = 150.f;
const float deceleration = 84.f;
const float maxSpeed = 180.f;
const float rotateAmount = 70.f;

Player::Player() :MovingComponent("PlayerCar", sf::Vector2f(180, 670), 43*0.65, 80*0.65) 
{
	m_timer.m_on = false;
	saveValidPosition();
}

Player & Player::getInstance()
{
	static Player m_instance;
	return m_instance;
}

void Player::move()
{
	bool leftPressed = false;
	bool rightPressed = false;
	GameScene* tempGameScene = dynamic_cast<GameScene*>(Controller::getInstance().getScene().get());
	if (tempGameScene == NULL)
		return;
	auto& view = tempGameScene->getView();
	float dt = m_clock.restart().asSeconds();
	//set speed and direction from keyboard input
	if ((leftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		m_component.rotate(-rotateAmount *dt);
	}
	else if ((rightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		m_component.rotate(rotateAmount * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (m_speed < maxSpeed)
		{
			m_speed += acceleration * dt;
		}

		//rotate direction vector
		sf::Vector2f oldVec = movementVec;
		sf::Transform t;
		t.rotate(m_component.getRotation());
		movementVec = t.transformPoint(forwardVec);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (m_speed < maxSpeed)
		{
			m_speed += acceleration * dt;
		}

		//rotate direction vector
		sf::Vector2f oldVec = movementVec;
		sf::Transform t;
		t.rotate(m_component.getRotation());
		movementVec = t.transformPoint(-forwardVec);
	}
	else
	{
		m_speed -= deceleration * dt;
		if (m_speed < 0.f) m_speed = 0.f;
	}
	//finally, move car
	auto currMove = movementVec * m_speed * dt;
	m_component.move(currMove);

	if(m_currentAnimation!= NULL)
	m_currentAnimation->onTimePassed();
}

void Player::cleanUpInstance()
{
	m_component = ResourceManager::getInstance().getValue<sf::RectangleShape>("PlayerCar");
	m_component.setPosition(m_initialPosition);
	m_component.setSize(sf::Vector2f(43 * 0.65, 80 * 0.65));
	m_speed = 0;
	m_score = 0;
	m_lives = LIVES_AMOUNT;
	m_clock.restart();
	saveValidPosition();
}

void Player::setPlayerName(std::string pn)
{
	m_playerName = pn;
}

std::string Player::getName()
{
	return m_playerName;
}

int Player::getScore() const
{
	return m_score;
}

void Player::slowCar()
{
	m_speed -= (deceleration / 3.f);
	if (m_speed < 0)
	{
		m_speed = 0;
	}
}

void Player::onCollision(std::string type)
{
	m_timer.setTimerFor(RECOVERY_SECONDS);
	auto animation = ComponentFactory::getInstance().create(type, type, getPosition(), 50, 50);
	auto curr = std::dynamic_pointer_cast<AnimatedGameComponent> (animation);
	m_currentAnimation = curr;
	m_currentAnimation->startAnimation();
}

void Player::increaseScore(int amount)
{
	m_score += amount;
}

void Player::draw()
{
	MovingComponent::draw();
	if (m_currentAnimation != NULL)
	{
		m_currentAnimation->draw();
	}
}

void Player::takeLife()
{
	m_lives--;
}

bool Player::isRecoveredFromCollision()
{
	if (m_timer.isTimePassed())
	{
		m_timer.m_on = false;
		m_clock.restart();
		m_speed = 0;
		return true;
	}
	if (!m_timer.m_on)
	{
		m_clock.restart();
		m_speed = 0;
		return true;
	}

	return false;
}

int Player::getLives() const
{
	return m_lives;
}

void Player::setPosition(sf::Vector2f position)
{

	m_component.setPosition(position);
	saveValidPosition();
}

void Player::increaseLives(std::string sender)
{
	if (sender == getTypeName<Coin>())
	{
		m_lives += COIN_LIVES_INCREASE;
		m_currentAnimation = std::make_shared<AnimatedGameComponent>("Life", getPosition(), 50, 50, 0.05f, false);
		m_currentAnimation->startAnimation();
	}
}


Player::~Player()
{
}
