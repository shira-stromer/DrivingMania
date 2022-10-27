#pragma once
#include "Scene.h"
#include "Textable.h"
#include "SFML\Graphics.hpp"
#include <memory>
#include "MenuButton.h"

class GameOverScene :
	public Scene
{
public:
	GameOverScene();
	~GameOverScene();
	virtual void draw() override;

private:
	void init();
	Textable m_title;
};

