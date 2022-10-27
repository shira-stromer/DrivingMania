#pragma once
#include <memory>
#include "Component.h"
#include <functional>
#include "GameComponent.h"
#include <map>
#include <string>
#include "StaticComponent.h"
#include "CrossSection.h"
#include "ObjectNotRegisteredException.h"
#include "Coin.h"
#include "Pedestrian.h"
#include "Arrow.h"
#include "Constants.h"

class GameScene;
class Controller;
class ComponentFactory
{
public:
	static ComponentFactory& getInstance();
	~ComponentFactory();
	std::shared_ptr<GameComponent> create(std::string type, std::string name, sf::Vector2f position, int height, int width);

private:
	void registerComponent(std::string name, std::function<std::shared_ptr<GameComponent>(std::string name,sf::Vector2f position, int height, int width)>);
	std::map <std::string, std::function<std::shared_ptr<GameComponent>(std::string name,sf::Vector2f position, int height, int width)>> m_map;
	void resetComponents();
	ComponentFactory();
	ComponentFactory(const ComponentFactory&);
};

