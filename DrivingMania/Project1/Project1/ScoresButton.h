#pragma once
#include "IClickable.h"
#include "ScoresScene.h"

class ScoresButton
	:public IClickable
{
public:
	ScoresButton();
	virtual void onClicked() override;
	~ScoresButton();
};

