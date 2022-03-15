#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>

struct Stats
{
	int pases = 0;
	int centros = 0;
	int tiros = 0;
	int evasion = 0;
	int entradas = 0;
	int intercep = 0;
	int portero = 0;

	void SetStats(int stats[7])
	{
		pases = stats[0];
		centros = stats[1];
		tiros = stats[2];
		evasion = stats[3];
		entradas = stats[4];
		intercep = stats[5];
		portero = stats[6];
	}

	void RndStats()
	{
		int stats[7];
		for (size_t i = 0; i < 7; i++)
		{
			stats[i] = (rand() % 100) + 1;
		}

		SetStats(stats);
	}

	Stats(int stats[7])
	{
		SetStats(stats);
	}

	Stats()
	{
		RndStats();
	}

	void PrintStats()
	{
		std::cout << "PASES = " << pases << "\n";
		std::cout << "CENTROS = " << centros << "\n";
		std::cout << "TIROS = " << tiros << "\n";
		std::cout << "EVASION = " << evasion << "\n";
		std::cout << "ENTRADAS = " << entradas << "\n";
		std::cout << "INTERCEPCIONES = " << intercep << "\n";
		std::cout << "PORTERO = " << portero << "\n\n\n";
	}
};

enum Position;

class Player
{
private:
	Stats stats;
	int idNum = -1;

public:
	Player(int num) : idNum(num)
	{
		std::cout << "Generating player " << num << "...\n", num;
		stats = Stats();

		std::cout << "__________________________________\n";
		std::cout << "ESTADISTICAS DEL JUGADOR " << num << "\n";
		std::cout << "__________________________________\n";
		stats.PrintStats();
	}

	Player() {};

	~Player();

	// -------------
	void SetStats(int stats[7]);
};

