#pragma once
#include "Scene.h"
#include "Textable.h"
#include "MenuButton.h"

class ScoresScene
	:public Scene
{
public:
	ScoresScene();
	~ScoresScene();
	virtual void draw() override;

private:
	std::unique_ptr<Textable> m_text;
	void showScores();
	void init();
};

