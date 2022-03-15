#pragma once

#include "Player.h"
#include <vector>

class Team
{
private:
	std::vector<Player> players;
	std::string name;

public:
	Team(std::string name);
	~Team();

	// ========== 

	std::vector<Player>* GetAllPlayers() { return &players; }
};

