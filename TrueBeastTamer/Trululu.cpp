#include "pch.h"
#include "Trululu.h"

GameModel::Trululu::Trululu(float x, float y){
	TagName = gcnew System::String("Trululu");
	Name = gcnew System::String("Trululu");
	Type = Element::Neutral;
	Power = gcnew List<GameModel::Power^>();
	Health = gcnew List<float>();//Base-Particular-Max-Actual-razon
	Health->Add(30);
	Health->Add(rand() % 10);
	Health->Add(Health[0]+Health[1]);
	Health->Add(Health[2]);
	Health->Add(0.75);

	Defense = gcnew List<float>();
	Defense->Add(3);
	Defense->Add(rand() % 5);
	Defense->Add(Defense[0] + Defense[1]);
	Defense->Add(Defense[2]);
	Defense->Add(0.5);

	Attack = gcnew List<float>();
	Attack->Add(5);
	Attack->Add(rand() % 3);
	Attack->Add(Attack[0] + Attack[1]);
	Attack->Add(Attack[2]);
	Attack->Add(0.5);

	Cooldown = gcnew List<float>();
	Cooldown->Add(10);
	Cooldown->Add(rand() % 10);
	Cooldown->Add(Cooldown[0] + Cooldown[1]);
	Cooldown->Add(Cooldown[2]);
	Cooldown->Add(3 / 5);

	Speed = 2;
	Level = 1;
	Exp = 0;
	X = x;
	Y = y;
	Sprite = new sf::Sprite();
	Texture = new sf::Texture();
	Texture->loadFromFile("../Imagenes/Trululu.png");//cambiar nombres 192X192
	Sprite->setTexture(*Texture, true);
	Sprite->setScale(TileSize / 192, TileSize / 192);
	Sprite->setPosition(X, Y);
	Length = TileSize;
	Height = TileSize;

}
