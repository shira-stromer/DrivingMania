#include "Bar.h"
#include "Player.h"
#include "GameScene.h"
#include "Controller.h"

Bar::Bar()
	:GameComponent("GameBar", sf::Vector2f(), SCREEN_WIDTH,70)
	,m_player(Player::getInstance())
{
	initBar();
}


void Bar::draw()
{
	GameComponent::draw();

	if (!m_initialized)
	{
		onNotify(getTypeName<Level>());
		m_initialized = true;
	}

	m_lives->setString("Lives: "+ std::to_string(m_player.getLives()));
	m_score->setString(std::to_string(m_player.getScore()));
	m_playerName->setString(m_player.getName());
	std::for_each(m_drawables.begin(), m_drawables.end(), [](std::shared_ptr<IDrawable> ptr) 
	{
		ptr->draw();
	});
}

void Bar::onNotify(std::string sender)
{
	if (getTypeName<Level>() == sender)
	{
		GameScene* tempGameScene = dynamic_cast<GameScene*>(Controller::getInstance().getScene().get());
		if (tempGameScene)
		{
			m_arrows->setString("Arrows : " + std::to_string(tempGameScene->getLevel().getArrowsCounter()));
		}
		else throw InvalidOperationException(getTypeName<Bar>());
	}
}

Bar::~Bar() {}

void Bar::initBar()
{
	m_lives = std::make_shared<Textable>(sf::Vector2f(10, 0), 50, sf::Color::Black);
	m_score = std::make_shared<Textable>(sf::Vector2f(250, 0), 50, sf::Color::Black);
	m_playerName = std::make_shared<Textable>(sf::Vector2f(SCREEN_WIDTH/2 - 50, 0), 50, sf::Color::Black);
	m_arrows = std::make_shared<Textable>(sf::Vector2f(SCREEN_WIDTH - 300 , 0), 50, UNCOMPLETE_ARROW_COLOR);
	
	m_drawables = std::vector<std::shared_ptr<IDrawable>>();
	m_drawables.push_back(m_lives);
	m_drawables.push_back(m_score);
	m_drawables.push_back(m_playerName);
	m_drawables.push_back(m_arrows);

}
