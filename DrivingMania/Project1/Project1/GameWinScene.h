#pragma once
#include "Scene.h"
#include "Textable.h"
#include <memory>
#include "MenuButton.h"

class GameWinScene :
	public Scene
{
public:
	GameWinScene();
	~GameWinScene();
	virtual void draw() override;

private:
	void init();
	Textable m_title;
};

