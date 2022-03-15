#pragma once

enum Position
{
	SouthGoal, SouthLeft, SouthCentre, SouthRight, Mid, NorthRight, NorthCentre, NorthLeft, NorthGoal
};

static std::string PositionToText(Position p)
{
	std::string s = "[]";
	switch (p)
	{
	case SouthGoal:
		s = "[PORT. SUR]";
		break;
	case SouthLeft:
		s = "[BANDA IZQ. SUR]";
		break;
	case SouthCentre:
		s = "[AREA SUR]";
		break;
	case SouthRight:
		s = "[BANDA DER. SUR]";
		break;
	case Mid:
		s = "[CENTRO DEL CAMPO]";
		break;
	case NorthRight:
		s = "[BANDA DER. NORTE]";
		break;
	case NorthCentre:
		s = "[AREA NORTE]";
		break;
	case NorthLeft:
		s = "[BANDA IZQ. NORTE]";
		break;
	case NorthGoal:
		s = "[PORT. NORTE]";
		break;
	default:
		break;
	}

	return s;
}

enum BallAction
{
	Pase, PaseHueco, Regate, Centro, Tiro
};

enum NoBallAction
{
	Entrada, EntradaAgresiva, Intercepcion
};