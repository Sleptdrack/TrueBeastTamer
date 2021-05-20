#include "pch.h"
#include "Beast.h"

GameModel::Beast::Beast(BeastName name)
{ 
	TagName = gcnew System::String("");
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
	switch (name) {
	     case BeastName::Trululu: 
			 TagName = "Trululu";
			 Type = Element::Neutral;
			 Texture->loadFromFile("../Imagenes/Trululu.png");//cambiar nombres 192X192
			 Sprite->setTexture(*Texture, true);
			 Sprite->setScale(TileSize / 192, TileSize / 192);
			 Sprite->setPosition(X, Y);
			 Length = TileSize;
			 Height = TileSize;
			 setStat(Health, 30, 10, 0.75);
			 setStat(Defense, 3, 5, 0.5);
			 setStat(Attack, 5, 3, 0.5);
			 setStat(Cooldown, 10, 10, 3/5);
			 break;
		 case BeastName::Atropos: 
			 TagName = "Atropos";
			 Type = Element::Earth;
			 Texture->loadFromFile("../Imagenes/Atropos.png");//cambiar nombres 192X192
			 Sprite->setTexture(*Texture, true);
			 Sprite->setScale(TileSize / 192, TileSize / 192);
			 Sprite->setPosition(X, Y);
			 Length = TileSize;
			 Height = TileSize;
			 setStat(Health, 33, 10, 0.75);
			 setStat(Defense, 5, 6, 0.5);
			 setStat(Attack, 4, 3, 0.5);
			 setStat(Cooldown, 10, 10, 3 / 5);
			 break;
		 case BeastName::Quin: 
			 TagName = "Quin";
			 Type = Element::Water;
			 Texture->loadFromFile("../Imagenes/Quin.png");//cambiar nombres 192X192
			 Sprite->setTexture(*Texture, true);
			 Sprite->setScale(TileSize / 192, TileSize / 192);
			 Sprite->setPosition(X, Y);
			 Length = TileSize;
			 Height = TileSize;
			 setStat(Health, 30, 10, 0.75);
			 setStat(Defense, 2, 5, 0.5);
			 setStat(Attack, 5.5, 3, 0.5);
			 setStat(Cooldown, 10, 10, 3 / 5);
			 break;
		 case BeastName::Mofset: 
			 TagName = "Mofset";
			 Type = Element::Ligthing;
			 Texture->loadFromFile("../Imagenes/Trululu.png");//cambiar nombres 192X192
			 Sprite->setTexture(*Texture, true);
			 Sprite->setScale(TileSize / 192, TileSize / 192);
			 Sprite->setPosition(X, Y);
			 Length = TileSize;
			 Height = TileSize;
			 setStat(Health, 28, 10, 0.75);
			 setStat(Defense, 3, 5, 0.5);
			 setStat(Attack, 7, 3, 0.5);
			 setStat(Cooldown, 10, 10, 3 / 5);
			 break; 
	}
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

//codigo de GC
void GameModel::Beast::setStat(List<float>^ s, float base, float particularidad, float radio)
{
	s->Add(base);
	s->Add(rand() % (int)particularidad);
	s->Add(Health[0] + Health[1]);
	s->Add(Health[2]);
	s->Add(radio);
}
