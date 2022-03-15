#pragma once
#include "FieldGraph.h"
#include <queue>

const int PLAYERS_PER_TEAM = 11;

class Field
{
private:
	
	std::vector<Player>* southPlayers;
	std::vector<Player>* northPlayers;
	FieldGraph graph;
	Position ballPos;

	// ============
	Player* FromQueue(std::queue<Player*> &q) { Player* p = q.front(); q.pop(); return p; }

	void AddPassLinks(PosNode *node, std::vector<PosNode*> links) {
		for (size_t i = 0; i < links.size(); i++) node->AddPassLink(links[i]);
	}
public:
	Field(std::vector<Player>* southPlayers, std::vector<Player>* northPlayers);

	// ============
	void GenerateField();
	void SimulateTurn();

};

