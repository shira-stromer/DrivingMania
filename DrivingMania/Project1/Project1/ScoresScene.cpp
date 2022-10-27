#include "ScoresScene.h"
#include "ResourceManager.h"
#include <map>
#include<algorithm>
#include "Utilities.h"


ScoresScene::ScoresScene()
	:m_text(std::make_unique<Textable>(sf::Vector2f(50,50), 48, sf::Color::Blue))
{
	showScores();
	init();
}


ScoresScene::~ScoresScene()
{
}

void ScoresScene::draw()
{
	Scene::draw();
	m_text->draw();
}

void ScoresScene::showScores()
{
	auto& scores = ResourceManager::getInstance().getScores();
	std::shared_ptr<std::string> txt = std::make_shared<std::string>();
	std::shared_ptr<std::multimap<int, std::string>> scr = std::make_shared<std::multimap<int, std::string>>();

	std::for_each(scores.begin(), scores.end(), [scr, txt](std::pair<std::string, std::vector<int>> vec) 
	{
		auto maxScore = getMax(vec.second);
		scr->insert(std::pair<int, std::string>(maxScore, vec.first));
	});
	
	auto scoresByOrder = *scr;
	
	std::for_each(scoresByOrder.rbegin(), scoresByOrder.rend(), [txt](std::pair<int, std::string> vec)
	{
		*txt += '\n';
		*txt += vec.second + ": " + std::to_string(vec.first);
	});

	m_text->setString(*txt);
}

void ScoresScene::init()
{
	auto menuButton = std::make_shared<MenuButton>(sf::Vector2f(20, 20));
	m_buttons.push_back(menuButton);
	m_components.push_back(menuButton);
}
