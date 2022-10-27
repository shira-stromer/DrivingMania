#pragma once
#include "GameComponent.h"
#include "SideWalk.h"
#include "ParkedVehicle.h"
#include "MovingVehicle.h"
#include "Pedestrian.h"
#include "UnknownCollisionException.h"
#include "Player.h"
#include <map>
#include <string>
#include "Ground.h"
#include "CrossWalk.h"
#include "Controller.h"
#include "ComponentFactory.h"
#include <memory>
#include "CollisionUtilities.h"

namespace
{

#pragma region CollisionFunctions

	void playerSideWalk(GameComponent& player, GameComponent& SideWalk)
	{
		auto _player = dynamic_cast<Player*>(&player);
		playerCrushed(_player);
		SideWalk.playSound();
	}
	void playerMovingVehicle(GameComponent& player, GameComponent& movingVehicle) 
	{
		auto _player = dynamic_cast<Player*>(&player);
		playerCrushed(_player);
		movingVehicle.playSound();
		auto moving = dynamic_cast<MovingVehicle*>(&movingVehicle);
		moving->revert();
		//movingVehicle.hide();
	}
	void playerPedestrian(GameComponent& player, GameComponent& pedestrian)
	{
		Player::getInstance().takeLife();
		pedestrian.hide();
		pedestrian.playSound();
	}
	void pedestrianPedestrian(GameComponent& pedestrian1, GameComponent& pedestrian2) 
	{
		dynamic_cast<Pedestrian*>(&pedestrian1)->revert();
		dynamic_cast<Pedestrian*>(&pedestrian2)->revert();
	}
	void movingVehicleMovingVehicle(GameComponent& movingVehicle1, GameComponent& movingVehicle2) 
	{
		int who = getRandom(0, 1);
		if (who)
		{
			dynamic_cast<MovingVehicle*>(&movingVehicle1)->revert();
		}
		else
		{
			dynamic_cast<MovingVehicle*>(&movingVehicle2)->revert();
		}
	}
	void movingVehicleSideWalk(GameComponent& movingVehicle, GameComponent& sideWalk) 
	{
		auto p = dynamic_cast<MovingVehicle*>(&movingVehicle);
		p->cleanUpInstance();
	}
	void movingVehiclePedestrian(GameComponent& movingVehicle, GameComponent& pedestrian) 
	{
		dynamic_cast<Pedestrian*>(&pedestrian)->revert();
		dynamic_cast<MovingVehicle*>(&movingVehicle)->revert();
	}
	void playerGround(GameComponent& player, GameComponent& ground)
	{
		auto _player = dynamic_cast<Player*>(&player);
		playerCrushed(_player);
		ground.playSound();
	}
	void playerArrow(GameComponent& player, GameComponent& arrow)
	{
		auto _arrow = dynamic_cast<Arrow*>(&arrow);
		if (!_arrow->isComplete())
		{
			GameScene* tempGameScene = dynamic_cast<GameScene*>(Controller::getInstance().getScene().get());
			if (tempGameScene)
			{
				_arrow->completeState();
				tempGameScene->getLevel().notifyArrowsVectorChanged();
				//Player::getInstance().onCollision(""); 
				_arrow->playSound();
			}
			else throw InvalidOperationException("CollisionHandler");
		}
		Player::getInstance().saveValidPosition();
	}

	void playerCrossSection(GameComponent& player, GameComponent& crossSection)
	{
		auto b = dynamic_cast<CrossSection*>(&crossSection);
		GameScene* tempGameScene = dynamic_cast<GameScene*>(Controller::getInstance().getScene().get());

		if (tempGameScene)
		{
			auto& trafficLight = b->getTrafficLight();

			if (trafficLight->colide(player.getComponent()))
			{
				tempGameScene->setTrafficLight(trafficLight);
				if (trafficLight->isRed() && !trafficLight->isPassed())
				{
					std::cout << "Moved on Red!!!!" << std::endl;
					crossSection.playSound();
					Player::getInstance().takeLife();
					trafficLight->pass();
				}
			}
			Player::getInstance().saveValidPosition();
		}
		else
		{
			throw InvalidOperationException("Collision Handler");
		}
	}
	void playerCoin(GameComponent& player, GameComponent& coin)
	{
		auto _player = dynamic_cast<Player*>(&player);
		auto _coin = dynamic_cast<Coin*>(&coin);

		_player->increaseScore(_coin->getScore());
		std::cout << "Got coin\n Score now is: " << _player->getScore() << std::endl;
	}
	void pedestrianParkedVehicle(GameComponent& pedestrian, GameComponent& parkedVehicle) 
	{
		dynamic_cast<Pedestrian*>(&pedestrian)->revert();
	}
	void movingVehicleParkedVehicle(GameComponent& movingVehicle, GameComponent& parkedVehicle)
	{
		dynamic_cast<MovingVehicle*>(&movingVehicle)->revert();
	}
	void playerParkedVehicle(GameComponent& player, GameComponent& parkedVehicle)
	{
		bool foundSide = false;
		std::cout << "collide with parked vehicle" << std::endl;
		auto b = dynamic_cast<Player*>(&player);
		auto position = b->getPosition();
		auto vehiclePosition = parkedVehicle.getPosition();

		parkedVehicle.move(sf::Vector2f(4, 0));
		if (b->colide(parkedVehicle.getComponent()))
		{
			parkedVehicle.move(sf::Vector2f(-4, 0));
			foundSide = true;
		}
		parkedVehicle.move(sf::Vector2f(-4, 0));
		if (!foundSide)
		{
			parkedVehicle.move(sf::Vector2f(-4, 0));
			if (b->colide(parkedVehicle.getComponent()))
			{
				parkedVehicle.move(sf::Vector2f(4, 0));
				foundSide = true;
			}
			parkedVehicle.move(sf::Vector2f(4, 0));
		}
		if (!foundSide)
		{
			parkedVehicle.move(sf::Vector2f(0, 4));
			if (b->colide(parkedVehicle.getComponent()))
			{
				parkedVehicle.move(sf::Vector2f(0, -4));
				foundSide = true;
			}
			parkedVehicle.move(sf::Vector2f(0, -4));
		}
		if (!foundSide)
		{
			parkedVehicle.move(sf::Vector2f(0, -4));
			if (b->colide(parkedVehicle.getComponent()))
			{
				parkedVehicle.move(sf::Vector2f(0, 4));
				foundSide = true;
			}
			parkedVehicle.move(sf::Vector2f(0, 4));
		}

		b->revert();
		if (b->isRecoveredFromCollision())
		{
			b->takeLife();
			b->onCollision("Explosion");
			parkedVehicle.playSound();
		}
	}
	void pedestrianSideWalk(GameComponent& pedestrian, GameComponent& sideWalk) {}
	void pedestrianGround(GameComponent& pedestrian, GameComponent& ground)
	{
		auto p = dynamic_cast<Pedestrian*>(&pedestrian);
		p->revert();
	}
	void movingVehiclePlayer(GameComponent& movingVehicle, GameComponent& player)
	{
		auto p = dynamic_cast<MovingVehicle*>(&movingVehicle);
		p->revert();
		playerCrushed(dynamic_cast<Player*>(&player));
	}
	void movingVehicleGround(GameComponent& movingVehicle, GameComponent& ground) 
	{
		auto& c = Player::getInstance();
	}
	void pedestrianCrossSection(GameComponent& crossSection, GameComponent& pedestrian)
	{
		
	}

#pragma endregion

#pragma region BothSidesCollisionFunctions
	void pedestrianPlayer(GameComponent& Pedestrian, GameComponent& player)
	{
		playerPedestrian(player, Pedestrian);
	}
	void pedestrianMovingVehicle(GameComponent& Pedestrian, GameComponent& MovingVehicle)
	{
		movingVehiclePedestrian(MovingVehicle, Pedestrian);
	}
	void groundPlayer(GameComponent& ground, GameComponent& player)
	{
		playerGround(player, ground);
	}
	void crossSectionPlayer(GameComponent& crossSection, GameComponent& player)
	{
		playerCrossSection(player, crossSection);
	}
	void parkedVehiclePlayer(GameComponent& parkecVehicle, GameComponent& player)
	{
		playerParkedVehicle(player, parkecVehicle);
	}
	void parkedVehiclePedestrian(GameComponent& parkecVehicle, GameComponent& pedestrian)
	{
		pedestrianParkedVehicle(pedestrian, parkecVehicle);
	}
	void coinPlayer(GameComponent& coin, GameComponent& player)
	{
		playerCoin(player, coin);
	}
	void arrowPlayer(GameComponent& arrow, GameComponent& player)
	{
		playerArrow(player, arrow);
	}
	void groundMovingVehicle(GameComponent& ground, GameComponent& movingVehicle)
	{
		movingVehicleGround(movingVehicle, ground);
	}
	void sideWalkPedestrian(GameComponent& sideWalk, GameComponent& pedestrian)
	{
		pedestrianSideWalk(pedestrian, sideWalk);
	}
	void GroundPedestrian(GameComponent& ground, GameComponent& pedestrian)
	{
		pedestrianGround(pedestrian, ground);
	}
	void parkedVehicleMovingVehicle(GameComponent& parkedVehicle, GameComponent& movingVehicle)
	{
		movingVehicleParkedVehicle(movingVehicle, parkedVehicle);
	}
	void sideWalkMovingVehicle(GameComponent& sideWalk, GameComponent& movingVehicle)
	{
		movingVehicleSideWalk(movingVehicle, sideWalk);
	}
	void crossSectionPedestrian(GameComponent& crossSection, GameComponent& pedestrian)
	{
	}
#pragma endregion

#pragma region HitMapInitialization

	typedef void(*HitFunctionPtr)(GameComponent&, GameComponent&);
	typedef std::map< std::pair<std::string, std::string>, HitFunctionPtr > HitMap;

	HitMap initializeCollisionMap()
	{
		HitMap phm;
		phm[std::make_pair(typeid(Player).name(), typeid(SideWalk).name())] = &playerSideWalk;
		phm[std::make_pair(typeid(Player).name(), typeid(MovingVehicle).name())] = &playerMovingVehicle;
		phm[std::make_pair(typeid(Player).name(), typeid(Pedestrian).name())] = &playerPedestrian;
		phm[std::make_pair(typeid(MovingVehicle).name(), typeid(Pedestrian).name())] = &movingVehiclePedestrian;
		phm[std::make_pair(typeid(MovingVehicle).name(), typeid(SideWalk).name())] = &movingVehicleSideWalk;
		phm[std::make_pair(typeid(MovingVehicle).name(), typeid(MovingVehicle).name())] = &movingVehicleMovingVehicle;
		phm[std::make_pair(typeid(Pedestrian).name(), typeid(Pedestrian).name())] = &pedestrianPedestrian;
		phm[std::make_pair(typeid(MovingVehicle).name(), typeid(Player).name())] = &movingVehiclePlayer;
		phm[std::make_pair(typeid(Pedestrian).name(), typeid(Player).name())] = &pedestrianPlayer;
		phm[std::make_pair(typeid(Pedestrian).name(), typeid(MovingVehicle).name())] = &pedestrianMovingVehicle;
		phm[std::make_pair(typeid(Ground).name(), typeid(Player).name())] = &groundPlayer;
		phm[std::make_pair(typeid(Player).name(), typeid(Ground).name())] = &playerGround;
		phm[std::make_pair(typeid(CrossSection).name(), typeid(Player).name())] = &crossSectionPlayer;
		phm[std::make_pair(typeid(Player).name(), typeid(CrossSection).name())] = &playerCrossSection;
		phm[std::make_pair(typeid(Player).name(), getTypeName<ParkedVehicle>())] = &playerParkedVehicle;
		phm[std::make_pair(getTypeName<ParkedVehicle>(), typeid(Player).name())] = &parkedVehiclePlayer;
		phm[std::make_pair(typeid(Player).name(), typeid(Coin).name())] = &playerCoin;
		phm[std::make_pair(typeid(Coin).name(), typeid(Player).name())] = &coinPlayer;
		phm[std::make_pair(typeid(Player).name(), typeid(Arrow).name())] = &playerArrow;
		phm[std::make_pair(typeid(Arrow).name(), typeid(Player).name())] = &arrowPlayer;
		phm[std::make_pair(typeid(Pedestrian).name(), typeid(Ground).name())] = &pedestrianGround;
		phm[std::make_pair(typeid(Ground).name(), typeid(Pedestrian).name())] = &GroundPedestrian;
		phm[std::make_pair(typeid(Pedestrian).name(), getTypeName<ParkedVehicle>())] = &pedestrianParkedVehicle;
		phm[std::make_pair(getTypeName<ParkedVehicle>(), typeid(Pedestrian).name())] = &parkedVehiclePedestrian;
		phm[std::make_pair(getTypeName<MovingVehicle>(), getTypeName<ParkedVehicle>())] = &movingVehicleParkedVehicle;
		phm[std::make_pair(getTypeName<ParkedVehicle>(), getTypeName<MovingVehicle>())] = &parkedVehicleMovingVehicle;
		phm[std::make_pair(getTypeName<MovingVehicle>(), getTypeName<SideWalk>())] = &movingVehicleSideWalk;
		phm[std::make_pair(getTypeName<SideWalk>(), getTypeName<MovingVehicle>())] = &sideWalkMovingVehicle;
		phm[std::make_pair(getTypeName<SideWalk>(), getTypeName<Pedestrian>())] = &sideWalkPedestrian;
		phm[std::make_pair(getTypeName<Pedestrian>(), getTypeName<SideWalk>())] = &pedestrianSideWalk;
		phm[std::make_pair(getTypeName<Pedestrian>(), getTypeName<CrossSection>())]=  & pedestrianCrossSection;
		phm[std::make_pair(getTypeName<CrossSection>(), getTypeName<Pedestrian>())] = &crossSectionPedestrian;


		return phm;
	}

	HitFunctionPtr lookup(const std::string& class1,
		const std::string& class2)
	{
		static HitMap collisionMap(initializeCollisionMap());
		HitMap::iterator mapEntry = collisionMap.find(make_pair(class1, class2));
		if (mapEntry == collisionMap.end())
			return 0;
		return (*mapEntry).second;
	}
#pragma endregion

}
void processCollision(GameComponent& object1, GameComponent& object2)
{
	auto object1Name = typeid(object1).name();
	auto object2Name = typeid(object2).name();

	HitFunctionPtr phf = lookup(object1Name,
		object2Name);
	if (phf)
		phf(object1, object2);
}