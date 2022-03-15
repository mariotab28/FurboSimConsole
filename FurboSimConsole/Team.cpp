#include "Team.h"
//#include "UtilEnums.h"

Team::Team(std::string name) : name(name)
{
	std::cout << "Generating team " << name << "...\n";
	// Player creation
	int playerNumber = 1;
	for (size_t i = 0; i < 11; i++)
	{
		// Create player
		std::cout << "[" << playerNumber << "]\n";
		Player player = Player(playerNumber); playerNumber++;
		players.push_back(player);
	}
}

Team::~Team()
{
}
