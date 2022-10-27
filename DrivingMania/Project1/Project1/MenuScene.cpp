#include "MenuScene.h"
#include "ChangeNameButton.h"
#include "SoundButton.h"

MenuScene::MenuScene()
	:Scene()
{
	initScene();
}

MenuScene::~MenuScene()
{
}

void MenuScene::draw()
{
	auto& window = Screen::getInstance().getWindow();
	window.draw(m_background);
	Scene::draw();
}

void MenuScene::initScene()
{
	m_background = ResourceManager::getInstance().getValue<sf::RectangleShape>("MenuBackgroung");
    m_background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	
	auto button = std::make_shared<SoundUpButton>(sf::Vector2f(50, 850), 40, 40);
	m_buttons.push_back(button);
	m_components.push_back(button);
	auto button1 = std::make_shared<SoundDownButton>(sf::Vector2f(100, 850), 40, 40);
	m_buttons.push_back(button1);
	m_components.push_back(button1);
	auto button2 = std::make_shared<StartGameButton>();
	m_buttons.push_back(button2);
	m_components.push_back(button2);
	auto button3 = std::make_shared<ExitButton>();
	m_buttons.push_back(button3);
	m_components.push_back(button3);
	auto button4 = std::make_shared<ScoresButton>();
	m_buttons.push_back(button4);
	m_components.push_back(button4);
	auto button5 = std::make_shared<ChangeNameButton>();
	m_buttons.push_back(button5);
	m_components.push_back(button5);
	auto button6 = std::make_shared<SoundButton>();
	m_buttons.push_back(button6);
	m_components.push_back(button6);
	auto helpButton = std::make_shared<HelpButton>("HelpButton", sf::Vector2f(651, 543), 89, 200);
	m_components.push_back(helpButton);
	m_buttons.push_back(helpButton);
}


