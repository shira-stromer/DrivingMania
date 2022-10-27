#pragma once
#include "IClickable.h"
#include <memory>
#include "GameScene.h"

class StartGameButton
	:public IClickable
{
public:
	StartGameButton();
	virtual void onClicked() override;
	~StartGameButton();
};

