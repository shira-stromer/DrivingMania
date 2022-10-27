#pragma once
#include "Scene.h"
#include "Level.h"
#include <fstream>
#include "Bar.h"
#include "IMovable.h"
#include "MenuButton.h"
#include <memory>
#include "Utilities.h"
#include "TrafficLight.h"
#include "AnimatedGameComponent.h"
#include "INotifiable.h"
#include "HelpButton.h"

typedef std::vector<std::shared_ptr<AnimatedGameComponent>> AnimationVecotr;
typedef std::vector<std::shared_ptr<GameComponent>> GameComponentVector;

class GameScene
	:public Scene, public IMovable
{
public:
	GameScene();
	~GameScene();
	virtual void draw() override;
	sf::View& getView();
	bool colide(sf::RectangleShape);
	virtual void move(sf::Vector2f) override;
	virtual void move() override;
	void setTrafficLight(std::shared_ptr<TrafficLight>);
	Level& getLevel();
	void nextLevel();
	void gameWin();
	void setAnimation(std::shared_ptr<AnimatedGameComponent>);
	virtual void onNotify(std::string sender) override;

private:
	void initScene();
	Level m_level;
	GameComponentVector m_dynamicComponents;
	GameComponentVector m_movingComponents;
	GameComponentVector m_trafficLights;
	sf::View m_view;
	std::shared_ptr<TrafficLight> m_currentTrafficLight;
	bool m_gameWin = false;
	bool m_nextLevel = false;
	std::shared_ptr<AnimatedGameComponent> m_animation;
	AnimationVecotr m_animations;
};

