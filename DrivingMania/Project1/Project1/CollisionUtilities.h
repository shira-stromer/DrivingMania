#pragma once
#include "Player.h"

static void playerCrushed(Player* player)
{
	player->revert();
	if (player->isRecoveredFromCollision())
	{
		player->takeLife();
		player->onCollision("Explosion");
	}
}
