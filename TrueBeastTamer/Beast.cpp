#include "pch.h"
#include "Beast.h"

GameModel::Beast::Beast(float x,float y)
{
	TagName = new sf::String();
	Name = new sf::String();
	//Type =1 to be determend
	Health = 100;
	Defense = 10;
	Attack = 20;
	Speed = 2;
	Level = 1;
	Exp = 0;
	X = x;
	Y = y;
	//esta parte debe ser borrada cuando se creen las subclases
	Sprite = new sf::Sprite();
	Texture = new sf::Texture();
	Texture->loadFromFile("../Imagenes/tipoagua1.png");//cambiar nombres 192X192
	Sprite->setTexture(*Texture, true);
	Sprite->setScale(TileSize / 192, TileSize / 192);
	Sprite->setPosition(X, Y);
	Length = TileSize;
	Height = TileSize;

}

void GameModel::Beast::Learn()
{
	throw gcnew System::NotImplementedException();
}
