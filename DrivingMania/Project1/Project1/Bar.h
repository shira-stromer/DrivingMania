#pragma once
#include "GameComponent.h"
#include "IMovable.h"
#include "Textable.h"
#include <vector>
#include <string>
#include "INotifiable.h"
#include "Utilities.h"
#include "Level.h"
#include "InvalidOperationException.h"
#include "Constants.h"

class Controller;
class GameScene;
class Bar
	:public GameComponent, public INotifiable
{
public:
	Bar();
	virtual void draw() override;
	virtual void onNotify(std::string sender) override;
	~Bar();
private:
	void initBar();
	std::shared_ptr<Textable> m_score;
	std::shared_ptr<Textable> m_lives;
	std::shared_ptr<Textable> m_playerName;
	std::shared_ptr<Textable> m_arrows;
	std::vector<std::shared_ptr<IDrawable>> m_drawables;
	Player& m_player;
	bool m_initialized = false;
};

