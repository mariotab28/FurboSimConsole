#include "Field.h"

Field::Field(std::vector<Player>* southPlayers, std::vector<Player>* northPlayers)
	: southPlayers(southPlayers), northPlayers(northPlayers)
{
	ballPos = Position::SouthGoal;
}

void Field::GenerateField()
{
	if (southPlayers->size() < PLAYERS_PER_TEAM || northPlayers->size() < PLAYERS_PER_TEAM)
	{ std::cout << "ERROR: NOT ENOUGH PLAYERS."; return; }

	// Generate team queues
	std::queue<Player*> teamSouth; std::queue<Player*> teamNorth;

	for (size_t i = 0; i < PLAYERS_PER_TEAM; i++) teamSouth.push(&southPlayers->at(i));

	for (size_t i = 0; i < PLAYERS_PER_TEAM; i++) teamNorth.push(&northPlayers->at(i));

	// Create Field Graph nodes ============
	graph = FieldGraph();
	Player* soPlayerA, *soPlayerB, * soPlayerC, *noPlayerA, *noPlayerB, *noPlayerC;

	// South Goal Node ---------
	soPlayerA = FromQueue(teamSouth);
	PosNode *soGoNode = new PosNode(Position::SouthGoal, { soPlayerA }, {}, true);
	

	// South Left Node ---------
	soPlayerA = FromQueue(teamSouth);
	noPlayerA = FromQueue(teamNorth);
	PosNode *soLeNode = new PosNode(Position::SouthLeft, { soPlayerA }, {noPlayerA}, false);
	

	// South Centre Node ---------
	soPlayerA = FromQueue(teamSouth);
	soPlayerB = FromQueue(teamSouth);
	noPlayerA = FromQueue(teamNorth);
	PosNode *soCeNode = new PosNode(Position::SouthCentre, { soPlayerA, soPlayerB }, { noPlayerA }, false);
	

	// South Right Node ---------
	soPlayerA = FromQueue(teamSouth);
	noPlayerA = FromQueue(teamNorth);
	PosNode *soRiNode = new PosNode(Position::SouthRight, { soPlayerA }, { noPlayerA }, false);
	

	// Mid Node ---------
	soPlayerA = FromQueue(teamSouth);
	soPlayerB = FromQueue(teamSouth);
	soPlayerC = FromQueue(teamSouth);
	noPlayerA = FromQueue(teamNorth);
	noPlayerB = FromQueue(teamNorth);
	noPlayerC = FromQueue(teamNorth);
	PosNode *midNode = new PosNode(Position::Mid, { soPlayerA, soPlayerB, soPlayerC }, { noPlayerA, noPlayerB, noPlayerC }, false);
	

	// North Right Node ---------
	soPlayerA = FromQueue(teamSouth);
	noPlayerA = FromQueue(teamNorth);
	PosNode *noRiNode = new PosNode(Position::NorthRight, { soPlayerA}, { noPlayerA }, false);
	

	// North Centre Node ---------
	soPlayerA = FromQueue(teamSouth);
	noPlayerA = FromQueue(teamNorth);
	noPlayerB = FromQueue(teamNorth);
	PosNode *noCeNode = new PosNode(Position::NorthCentre, { soPlayerA }, { noPlayerA, noPlayerB }, false);
	

	// North Left Node ---------
	soPlayerA = FromQueue(teamSouth);
	noPlayerA = FromQueue(teamNorth);
	PosNode *noLeNode = new PosNode(Position::NorthLeft, { soPlayerA }, { noPlayerA }, false);
	

	// North Goal Node ---------
	noPlayerA = FromQueue(teamNorth);
	PosNode *noGoNode = new PosNode(Position::NorthGoal, {}, { noPlayerA }, false);
	

	// Add Field Node pass links ==============
	// South Goal Node ---------
	AddPassLinks(soGoNode, { soLeNode, soCeNode, soRiNode });

	// South Left Node ---------
	AddPassLinks(soLeNode, { soCeNode, midNode, soGoNode, noLeNode });

	// South Centre Node ---------
	AddPassLinks(soCeNode, { soLeNode, midNode, soGoNode, soRiNode });

	// South Right Node ---------
	AddPassLinks(soRiNode, { soCeNode, midNode, soGoNode, noRiNode });

	// Mid Node ---------
	AddPassLinks(midNode, { soCeNode, soLeNode, soRiNode, noCeNode, noLeNode, noRiNode });

	// North Left Node ---------
	AddPassLinks(noLeNode, { noCeNode, midNode, noGoNode, soLeNode });

	// North Centre Node ---------
	AddPassLinks(noCeNode, { noLeNode, midNode, noGoNode, noRiNode });

	// North Right Node ---------
	AddPassLinks(noRiNode, { noCeNode, midNode, noGoNode, soRiNode });

	// North Goal Node ---------
	AddPassLinks(noGoNode, { noLeNode, noCeNode, noRiNode });


	// Add nodes to Graph ==============
	graph.AddNode(soGoNode);
	graph.AddNode(soLeNode);
	graph.AddNode(soCeNode);
	graph.AddNode(soRiNode);
	graph.AddNode(midNode);
	graph.AddNode(noRiNode);
	graph.AddNode(noCeNode);
	graph.AddNode(noLeNode);
	graph.AddNode(noGoNode);

	std::cout << "Finished generating field.\n_________________________\n";
}

void Field::SimulateTurn()
{
	PosNode* curNode = graph.GetNode(ballPos);
	PosNode* nextNode = curNode->GetRandomAdyacent();

	std::cout << "La bola pasa de " << PositionToText(curNode->posId) << " a " << PositionToText(nextNode->posId) << "!\n";

	ballPos = nextNode->posId;
}
