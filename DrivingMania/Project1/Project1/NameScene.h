#pragma once
#include "Scene.h"
#include "Textable.h"
#include "Component.h"

class Player;
class NameScene
	:public Scene 
{
public:
	NameScene();
	virtual void draw() override;
	~NameScene();
	void addKey(char c);
	void saveChanges();
	void deleteLast();


private:
	Textable m_question;
	Textable m_answer;
	void init();
};

