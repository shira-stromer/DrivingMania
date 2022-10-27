#include "NameScene.h"
#include "Screen.h"
#include "Player.h"
#include "Constants.h"
#include "MenuScene.h"
#include "Controller.h"

NameScene::NameScene()
	:m_question(sf::Vector2f(250, 250), 120, sf::Color::Red),
	m_answer(sf::Vector2f(250, 420), 72, sf::Color::Blue)
{
	init();
}

void NameScene::draw()
{
	Scene::draw();
	m_question.draw();
	m_answer.draw();
}


NameScene::~NameScene()
{
}

void NameScene::addKey(char c)
{
	auto str = m_answer.getString();
	if (str.size() == MAX_NAME_SIZE)
	{
		std::cout << "Reached limit of name size\n";
		return;
	}

	m_answer.setString(str + c);
}

void NameScene::saveChanges()
{
	if (m_answer.getString() == "")
	{
		std::cout << "No name was entered\n";
		return;
	}

	Player::getInstance().setPlayerName(m_answer.getString());
	Screen::getInstance().getWindow().setSize(sf::Vector2u(SCREEN_WIDTH, SCREEN_HEIGHT));
	Controller::getInstance().setScene(std::make_unique<MenuScene>());
}

void NameScene::deleteLast()
{
	auto str = m_answer.getString();
	if (str == "")
		return;
	str.pop_back();
	m_answer.setString(str);
}

void NameScene::init()
{
	m_question.setString("Enter your name");
	m_components.push_back(std::make_shared<Component>("TextBox", sf::Vector2f(250, 400), 800, 150));
	Screen::getInstance().getWindow().setSize(sf::Vector2u(400, 400));
}
