#include "pch.h"
#include "Beast.h"

GameModel::Beast::Beast()
{
	TagName = new sf::String();
	Name = new sf::String();
	Type = Element::Neutral;
	Health = gcnew List<float>();
	Defense = gcnew List<float>();
	Attack = gcnew List<float>();
	Cooldown = gcnew List<float>();
	Speed = 2;
	Level = 1;
	Exp = 0;
	X = 0;
	Y = 0;
	//esta parte debe ser borrada cuando se creen las subclases
	Sprite = new sf::Sprite();
	Texture = new sf::Texture();
	//Sprite->setPosition(X, Y);
	Length = TileSize;
	Height = TileSize;
}


void GameModel::Beast::Learn()
{
	throw gcnew System::NotImplementedException();
}

void GameModel::Beast::LevelUp()
{
	if (Exp > 100) {
		Level += 1;
		Exp -= 100;
		UpdateStats(Health, Level);
		UpdateStats(Defense, Level);
		UpdateStats(Attack, Level);
		UpdateStats(Cooldown, Level);
	}
}

void GameModel::Beast::UpdateStats(List<float>^ T,int L)
{
	T[2] = (T[0] + T[1]) * (1 - pow(T[4], L)) / (1 - T[4]);
}
