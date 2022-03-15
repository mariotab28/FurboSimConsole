#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include "Team.h"
#include "Field.h"
#include <chrono>
#include <thread>

using namespace std;

// Functions - Forward declaration
void printGreetings();

int main()
{
    char controlChar = 'x';
    // Random number setup
    srand((unsigned) time(0));

    printGreetings();

    Team teamA = Team("Madrid Club");
    std::cout << "__________________________________\n";
    //std::cin >> controlChar;
    Team teamB = Team("Sociedad Barcelona");
    std::cout << "\n\n__________________________________\n";
    //std::cin >> controlChar;

    Field field = Field(teamA.GetAllPlayers(), teamB.GetAllPlayers());
    field.GenerateField();

    while (true)
    {
        field.SimulateTurn();
        std::cout << "...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }

    std::cout << "Fin.\n";
    return 0;
}

void printGreetings()
{
    std::cout << "Furbo Sim (Console version) - Simulador de partidos de futbol\n";
    std::cout << "=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=\n";
}
