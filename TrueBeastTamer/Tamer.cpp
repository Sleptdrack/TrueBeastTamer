#include "pch.h"
#include "Tamer.h"

GameModel::Tamer::Tamer(System::String^ U, System::String^ P, int id)
{
    Id = id;
    Username = gcnew System::String(U);
    Password = gcnew System::String(P);
    Bag = gcnew GameModel::Bag();
    X = 0;
    Y = 0;
    Speed = 2;
    Texture = new sf::Texture();
    Sprite = new sf::Sprite();
    Texture->loadFromFile("../Imagenes/Tamer.png");
    Sprite->setTexture(*Texture, true);
    Sprite->setScale(TileSize / 555, TileSize / 898);
    Sprite->setPosition(X, Y);
    Length = TileSize;
    Height = TileSize;
}
