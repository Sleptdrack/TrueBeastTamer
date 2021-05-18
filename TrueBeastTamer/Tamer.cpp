#include "pch.h"
#include "Tamer.h"

GameModel::Tamer::Tamer(sf::String U, sf::String P, int id)
{
    Id = id;
    Username = new sf::String(U);
    Password = new sf::String(P);
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
