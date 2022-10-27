#pragma once
#include "Scene.h"
#include <memory>
#include "SoundDownButton.h"
#include "SoundUpButton.h"
#include "StartGameButton.h"
#include "ExitButton.h"
#include "ScoresButton.h"

class MenuScene :
	public Scene
{
public:
	MenuScene();
	~MenuScene();
	void draw()override;

private:
	void initScene();
};

