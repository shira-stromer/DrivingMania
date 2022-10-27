#pragma once
#include "Scene.h"
#include <memory>

class HelpScene :
	public Scene
{
public:
	HelpScene();
	virtual void draw() override;
	~HelpScene();

private:
	void initScene();
};

