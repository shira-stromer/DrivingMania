#include "Controller.h"
#include "Player.h"
#include <typeinfo>

Controller::Controller()
{
	m_timePassedHandler = NULL;
	init();
	srand(time(NULL));
}

void Controller::drawScene(sf::RenderWindow& window)
{
	window.clear(sf::Color(105, 105, 105));
	m_scene->draw();
	window.display();
}

void Controller::init()
{
	auto playerName = ResourceManager::getInstance().getValue<std::string>("PlayerName");
	
	if (playerName != "")
	{
		Player::getInstance().setPlayerName(playerName);
		setScene(std::make_unique<MenuScene>());
	}
	else
	{
		setScene(std::make_unique<NameScene>());
	}

	SoundManager::getInstance().playBackground();
}


Controller & Controller::getInstance()
{
	static Controller m_instance;
	return m_instance;
}

void Controller::run()
{
	auto& window = Screen::getInstance().getWindow();
	try
	{
		CommandExecuter commmandExecuter;
		m_timePassedHandler = std::make_unique<TimePassedHanlder>();
		while (Screen::getInstance().getWindow().isOpen())
		{
			sf::Event _event;
			while (window.pollEvent(_event))
			{
				commmandExecuter.execute(_event);
			}
			m_timePassedHandler->onTimePassed();
			drawScene(window);
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		system("PAUSE");
	}	
}

void Controller::setScene(std::unique_ptr<Scene> scene)
{
	m_scene = std::move(scene);
	m_sceneName = std::string(typeid(*m_scene.get()).name());
}

std::unique_ptr<Scene>& Controller::getScene()
{
	return m_scene;
}

std::unique_ptr<TimePassedHanlder>& Controller::getTimePassedHandler()
{
	return m_timePassedHandler;
}

std::string Controller::getSceneName() const
{
	return m_sceneName;
}

Controller::~Controller()
{
}
