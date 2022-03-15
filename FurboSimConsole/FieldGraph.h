#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include "UtilEnums.h"
#include "Player.h"
#include "RandomUtils.h"

struct PosNode;
using Links = std::vector<PosNode*>;  // lista de adyacentes a un vértice

struct PosNode
{
	Position posId;
	Links passLinks;
	std::vector<Player*> southPlayers;
	std::vector<Player*> northPlayers;
	bool isGoal = false;

	PosNode(Position position, std::vector<Player*> south, std::vector<Player*> north, bool isGoal) 
		: posId(position), southPlayers(south), northPlayers(north), isGoal(isGoal)
	{

	}

	void AddPassLink(PosNode* link)
	{
		passLinks.push_back(link);
	}

	PosNode* GetRandomAdyacent()
	{
		if (passLinks.size() <= 0)
		{
			std::cout << "Error in links size\n";
			return nullptr;
		}

		return select_randomly(passLinks);
	}

};

class FieldGraph 
{
private:
	int numNodes;
	std::vector<PosNode*> nodes;

public:
	void AddNode(PosNode* node) { nodes.push_back(node); }
	PosNode* GetNode(Position pos) { return nodes[pos]; }
};