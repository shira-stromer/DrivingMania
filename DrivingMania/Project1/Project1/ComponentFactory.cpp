#include "ComponentFactory.h"
#include "SideWalk.h"
#include "Ground.h"
#include "CrossWalk.h"
#include "ParkedVehicle.h"
#include "GameScene.h"
#include "Controller.h"
#include "AnimatedGameComponent.h"
#include "MovingVehicle.h"
#include <math.h>

ComponentFactory::ComponentFactory()
{
	resetComponents();
}


ComponentFactory & ComponentFactory::getInstance()
{
	static ComponentFactory m_instance;
	return m_instance;
}

ComponentFactory::~ComponentFactory()
{
}

std::shared_ptr<GameComponent> ComponentFactory::create(std::string type, std::string name, sf::Vector2f position, int height, int width)
{
	auto create = m_map.find(type);
	if (create == m_map.end())
		throw ObjectNotRegisteredException(type);

	return m_map[type](name, position, width, height);
}

void ComponentFactory::registerComponent(std::string name, std::function<std::shared_ptr<GameComponent>(std::string name, sf::Vector2f position, int height, int width)> function)
{
	m_map[name] = function;
}

void ComponentFactory::resetComponents()
{
	registerComponent("SideWalk", [](std::string name, sf::Vector2f position, int height, int width)
	{
		return std::make_shared<SideWalk>(name, position, width, height);//
	});
	registerComponent("ParkedVehicle", [](std::string name, sf::Vector2f position, int height, int width)
	{
		if (abs((double)width) > abs((double)height))
		{
			if (width > 0)
			{
				std::cout << "On regular width bigger that height" << std::endl;
				position.y += 25;
				auto obj = std::make_shared<ParkedVehicle>(name, position, height, width);
				obj->rotate(Left);
				return obj;
			}
			else
			{
				auto obj = std::make_shared<ParkedVehicle>(name, position, height, abs((double)width));
				obj->rotate(Left);
				return obj;
			}
		}
		else if (width < 0)
		{
			auto obj = std::make_shared<ParkedVehicle>(name, position, abs((double)width), height);
			obj->rotate(Buttom);
			return obj;
		}

		return std::make_shared<ParkedVehicle>(name, position, width, height);
	});
	registerComponent("Ground", [](std::string name, sf::Vector2f position, int height, int width)
	{
		return std::make_shared<Ground>(name, position, width, height);
	});
	registerComponent("CrossSection", [](std::string name, sf::Vector2f position, int height, int width)
	{
		return std::make_shared<CrossSection>(name, "TrafficLightColor", position, width, height);
	});
	registerComponent("CrossWalk", [](std::string name, sf::Vector2f position, int height, int width)
	{
		return std::make_shared<CrossWalk>(name, position, width, height);
	});
	registerComponent("Coin", [](std::string name, sf::Vector2f position, int height, int width)
	{
		return std::make_shared<Coin>(name, position, width, height);
	});
	registerComponent("Pedestrian", [](std::string name, sf::Vector2f position, int height, int width)
	{
		return std::make_shared<Pedestrian>(name, position, width, height);
	});
	registerComponent("StraightArrow", [](std::string name, sf::Vector2f position, int height, int width)
	{
		return std::make_shared<Arrow>(name, position, width, height);
	});
	registerComponent("Explosion", [](std::string name, sf::Vector2f position, int height, int width)
	{
		std::cout << "Created Explosion\n";
		return std::make_shared<AnimatedGameComponent>(name, position, width, height, 0.001f, false);
	});
	registerComponent("MovingVehicle", [](std::string name, sf::Vector2f position, int height, int width)
	{
		return std::make_shared<MovingVehicle>(name, position, width, height);
	});
}


