#include "GameWinScene.h"
#include "ResourceManager.h"
#include "Player.h"

GameWinScene::GameWinScene()
	:m_title(sf::Vector2f(250, 250), 120, sf::Color::Red)
{
	init();
}


GameWinScene::~GameWinScene()
{
}

void GameWinScene::draw()
{
	Scene::draw();
	m_title.draw();
	//std::cout << "Drawing\n";
}

void GameWinScene::init()
{
	Screen::getInstance().changeToDefaultView();
	auto& player = Player::getInstance();

	m_title.setString("You won!\n Your Score is: " + std::to_string(player.getScore()));
	auto menuButton = std::make_shared<MenuButton>(sf::Vector2f(40, 40));
	m_components.push_back(menuButton);
	m_buttons.push_back(menuButton);
	
	//Do things when wins
	ResourceManager::getInstance().exportScores();
	player.cleanUpInstance();
}
