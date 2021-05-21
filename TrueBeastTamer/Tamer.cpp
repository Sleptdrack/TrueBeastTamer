#include "pch.h"
#include "Tamer.h"

GameModel::Tamer::Tamer(System::String^ U, System::String^ P, int id/*, dummy mydummy*/)
{
    Id = id;
    Username = gcnew System::String(U);
    Password = gcnew System::String(P);
    Bag = gcnew GameModel::Bag();
    /*
    speed = dummy.speed;
    texture = new sf::...
    Texture->loadfrom( Tamer.selectrandom( dummy.sprite, dummy.prob ) )

    damage = dummy.damage
    type = dummy.type
    ...

    */
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
