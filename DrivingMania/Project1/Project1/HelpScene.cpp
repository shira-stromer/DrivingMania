#include "HelpScene.h"
#include "Screen.h"
#include "MenuButton.h"

HelpScene::HelpScene()
{
	initScene();
}

void HelpScene::draw()
{
	Screen::getInstance().getWindow().draw(m_background);
	Scene::draw();
}


HelpScene::~HelpScene()
{
}

void HelpScene::initScene()
{
	//m_background = "the help picture;"
	m_background = ResourceManager::getInstance().getValue<sf::RectangleShape>("HelpSceneBackground");
	m_background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Screen::getInstance().changeToDefaultView();
	auto menuButton = std::make_shared<MenuButton>(sf::Vector2f(SCREEN_WIDTH - 100, 20));
	m_components.push_back(menuButton);
	m_buttons.push_back(menuButton);
}
