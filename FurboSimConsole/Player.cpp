#include "Player.h"

Player::~Player()
{
}

void Player::SetStats(int stats[7])
{
	this->stats.SetStats(stats);
}
