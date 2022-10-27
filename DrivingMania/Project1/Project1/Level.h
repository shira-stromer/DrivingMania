#pragma once
#include <SFML\Graphics.hpp>
#include <map>
#include <string>
#include "NotFoundException.h"
#include <memory>
#include <fstream>
#include <sstream>
#include "ResourceManager.h"
#include "GameComponent.h"
#include "ComponentFactory.h"
#include <iostream>
#include "Arrow.h"
#include "AnimatedGameComponent.h"
#include "InvalidOperationException.h"
#include "Utilities.h"
#include "StaticComponent.h"

typedef std::vector<std::shared_ptr<GameComponent>> ComponentVector;
typedef std::vector<std::shared_ptr<AnimatedGameComponent>> AnimationVecotr;
class Controller;
class GameScene;
class Level
{
public:
	Level(int level = 1);
	~Level();
	void loadLevel(ComponentVector& components, AnimationVecotr& animations, ComponentVector& movingComp, ComponentVector& trafficLights);
	void notifyArrowsVectorChanged();
	int getArrowsCounter() const;
	void registerForNotification(std::shared_ptr<INotifiable> ptr);
	int getLevel();

private:
	int m_level;
	int m_arrowsCounter;
	std::vector<std::shared_ptr<INotifiable>> m_notifiables;
};

