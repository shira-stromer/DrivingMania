#include "GameScene.h"
#include "Player.h"
#include "CollisionHandler.h"
#include "GameWinScene.h"

GameScene::GameScene() :Scene()
, m_view(sf::FloatRect(0, 0, 400, 400))
{
	initScene();
}

GameScene::~GameScene() {}

void GameScene::draw()
{
	//Order Matters!!!!!!
	auto& window = Screen::getInstance().getWindow();
	window.draw(m_background);

	//Game View
	window.setView(m_view);
	m_background.setSize(sf::Vector2f(2000, 2000));

	std::for_each(m_dynamicComponents.begin(), m_dynamicComponents.end(), [](std::shared_ptr<GameComponent> cmp)
	{
		cmp->draw();
	});

	Player::getInstance().draw();

	std::for_each(m_trafficLights.begin(), m_trafficLights.end(), [](std::shared_ptr<GameComponent> ptr) 
	{
		ptr->draw();
	});
	
	if (m_animation != NULL)
		m_animation->draw();

	m_view.setCenter(Player::getInstance().getPosition());

	//UI View
	window.setView(window.getDefaultView());
	Scene::draw();

	window.setView(m_view);
}

sf::View & GameScene::getView()
{
	return m_view;
}

bool GameScene::colide(sf::RectangleShape comp)
{
	return std::any_of(m_dynamicComponents.begin(), m_dynamicComponents.end(), [comp](std::shared_ptr<GameComponent> cmp)
	{
		return cmp->colide(comp);
	});
}

void GameScene::move(sf::Vector2f s)
{
}

void GameScene::move()
{
	auto& player = Player::getInstance();
	player.move();
	auto validFlag = true;

	for (auto& j : m_dynamicComponents)
	{
		if (player.colide(j->getComponent()))
		{
			validFlag = false;
			processCollision(player, *j);
		}
	}	

	if (validFlag)
	{
		player.saveValidPosition();
	}

	for (auto& i : m_movingComponents)
	{
		i->move();
		for (auto& j : m_dynamicComponents)
		{
			if (i == j)
				continue;

			if (i->colide(j->getComponent()))
			{
				processCollision(*i, *j);
			}
		}
	}
}

void GameScene::setTrafficLight(std::shared_ptr<TrafficLight> ptr)
{
	m_currentTrafficLight = ptr;
}

Level & GameScene::getLevel()
{
	return m_level;
}

void GameScene::nextLevel()
{
	if (m_nextLevel)
	{
		m_background = ResourceManager::getInstance().getValue<sf::RectangleShape>("Levels/Level" + std::to_string(m_level.getLevel()));
		m_level.loadLevel(m_dynamicComponents, m_animations, m_movingComponents, m_trafficLights);
		std::for_each(m_animations.begin(), m_animations.end(), [](std::shared_ptr<AnimatedGameComponent> ptr)
		{
			ptr->startAnimation();
		});
		m_nextLevel = false;
		std::cout << "Next Level" << std::endl;
	}
	else
	{
		m_nextLevel = true;
	}
}

void GameScene::gameWin()
{
	if (!m_gameWin)
	{
		m_gameWin = true;
	}
	else
	{
		Controller::getInstance().setScene(std::make_unique<GameWinScene>());
	}
}

void GameScene::setAnimation(std::shared_ptr<AnimatedGameComponent> anim)
{
	m_animation = anim;
	m_animation->startAnimation();
}

void GameScene::onNotify(std::string sender)
{
	if (sender == getTypeName<TimePassedHanlder>())
	{
		move();
		if (m_nextLevel)
		{
			nextLevel();
			return;
		}

		if (m_gameWin)
		{
			gameWin();
			return;
		}

		if (m_animation != NULL)
		{
			m_animation->onTimePassed();
		}

		std::for_each(m_animations.begin(), m_animations.end(), [](std::shared_ptr<AnimatedGameComponent> ptr)
		{
			ptr->onTimePassed();
		});

		if (Player::getInstance().getLives() <= 0)
		{
			std::cout << "Game Over" << std::endl;
			Controller::getInstance().setScene(std::make_unique<GameOverScene>());
		}
	}
}

void GameScene::initScene()
{
	m_background = ResourceManager::getInstance().getValue<sf::RectangleShape>("Levels/Level"+ std::to_string(m_level.getLevel()));
	auto menuButton = std::make_shared<MenuButton>(sf::Vector2f(40, 40));
	auto bar = std::make_shared<Bar>();
	auto soundUp = std::make_shared<SoundUpButton>(sf::Vector2f(SCREEN_WIDTH - 100, 55), 40, 40);
	auto soundDown = std::make_shared<SoundDownButton>(sf::Vector2f(SCREEN_WIDTH - 150, 55), 40, 40);
	auto helpButton = std::make_shared<HelpButton>("Help", sf::Vector2f(SCREEN_WIDTH - 50, 55), 40,40);
	
	m_components.push_back(bar);
	m_components.push_back(menuButton);
	m_components.push_back(soundUp);
	m_components.push_back(soundDown);
	m_components.push_back(helpButton);

	m_buttons.push_back(soundUp);
	m_buttons.push_back(soundDown);
	m_buttons.push_back(menuButton);
	m_buttons.push_back(helpButton);

	m_level.loadLevel(m_dynamicComponents, m_animations, m_movingComponents, m_trafficLights);
	m_level.registerForNotification(bar);
}
