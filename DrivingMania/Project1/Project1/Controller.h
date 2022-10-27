#pragma once
#include "Screen.h"
#include <iostream>
#include <memory>
#include "Scene.h"
#include "MenuScene.h"
#include "CommandExecuter.h"
#include "TimePassedHanlder.h"
#include "Player.h"
#include "NameScene.h"
#include "Utilities.h"

class Controller
{
public:
	static Controller& getInstance();
	void run();
	void setScene(std::unique_ptr<Scene>);
	std::unique_ptr<Scene>& getScene();
	std::unique_ptr<TimePassedHanlder>& getTimePassedHandler();
	std::string getSceneName() const;
	~Controller();

private:
	Controller();
	Controller(const Controller&);
	std::unique_ptr<Scene> m_scene;
	void drawScene(sf::RenderWindow&);
	void init();
	std::unique_ptr<TimePassedHanlder> m_timePassedHandler;
	std::string m_sceneName;
};

