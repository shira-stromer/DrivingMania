#include "Level.h"
#include "GameScene.h"
#include "Controller.h"
#include "Constants.h"
#include "MovingComponent.h"

Level::Level(int level)
	:m_level(level) {}

Level::~Level() {}

void Level::loadLevel(ComponentVector& components, AnimationVecotr& animations, ComponentVector& movingComp, ComponentVector& trafficLights)
{
	components = ComponentVector();
	animations = AnimationVecotr();
	movingComp = ComponentVector();
	trafficLights = ComponentVector();

	m_arrowsCounter = 0;
	auto& factory = ComponentFactory::getInstance();
	std::string path = ResourceManager::getInstance().getValue<std::string>("Level" + std::to_string(m_level));
	std::ifstream file;
	float x, y, height, width;
	std::string type, objName;

	file.open(path);

	if (!file.is_open())
	{
		throw NotFoundException(path);
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		ss >> type;
		ss >> objName;
		ss >> x;
		ss >> y;
		ss >> width;
		ss >> height;

		if (type == PLAYER)
		{
			Player::getInstance().setPosition(sf::Vector2f(x, y));
			continue;
		}

		auto b = factory.create(type ,objName, sf::Vector2f(x, y), (int)height, (int)width);
		components.push_back(b);
		
		auto casted = dynamic_cast<Arrow*>(b.get());
		if (casted)
		{
			m_arrowsCounter++;
		}

		auto castedAnimation = std::dynamic_pointer_cast<Coin> (b);
		if (castedAnimation)
		{
			castedAnimation->startAnimation();
			animations.push_back(castedAnimation);
			continue;
		}

		auto castedMoving = dynamic_cast<MovingComponent*>(b.get());
		if (castedMoving)
		{
			movingComp.push_back(b);
			continue;
		}

		auto castedTrafficLight = std::dynamic_pointer_cast<CrossSection>(b);
		if (castedTrafficLight)
		{
			trafficLights.push_back(castedTrafficLight->getTrafficLight());
			continue;
		}
	}

	file.close();
}

void Level::notifyArrowsVectorChanged()
{
	m_arrowsCounter--;
	auto result = m_arrowsCounter == 0;
	
	std::for_each(m_notifiables.begin(), m_notifiables.end(), [](std::shared_ptr<INotifiable> ptr) 
	{
		ptr->onNotify(getTypeName<Level>());
	});

	if (result)
	{
		GameScene* tempGameScene = dynamic_cast<GameScene*>(Controller::getInstance().getScene().get());
		if (tempGameScene)
		{
			if (ResourceManager::getInstance().getValue<int>("LevelAmount") == m_level)
			{
				std::cout << "Game win" << std::endl;
				tempGameScene->gameWin();
			}
			else
			{
				m_level++;
				std::cout << "Next Level" << std::endl;
				tempGameScene->nextLevel();
			}
		}
		else
		{
			throw InvalidOperationException(getTypeName<Level>());
		}
	}
}

int Level::getArrowsCounter() const
{
	return m_arrowsCounter;
}

void Level::registerForNotification(std::shared_ptr<INotifiable> ptr)
{
	m_notifiables.push_back(ptr);
}

int Level::getLevel()
{
	return m_level;
}
