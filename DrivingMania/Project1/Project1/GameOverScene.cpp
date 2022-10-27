#include "GameOverScene.h"
#include "Player.h"
#include "Constants.h"


GameOverScene::GameOverScene()
	:m_title(sf::Vector2f(75, 250), 120, sf::Color::Black)
{
	init();
}

GameOverScene::~GameOverScene() {}

void GameOverScene::draw()
{
	Screen::getInstance().getWindow().draw(m_background);
	Scene::draw();
	m_title.draw();
}

void GameOverScene::init()
{
	Screen::getInstance().changeToDefaultView();
	m_background = ResourceManager::getInstance().getValue<sf::RectangleShape>("65");
	m_background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	auto menuButton = std::make_shared<MenuButton>(sf::Vector2f(40, 40));
	m_components.push_back(menuButton);
	m_buttons.push_back(menuButton);
	m_title.setString("Game Over!!!");
	Player::getInstance().cleanUpInstance();
}
