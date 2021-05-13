#include "pch.h"
#include "Grass.h"

GameModel::Grass::Grass(){
    SpawnRate = 25;
    Texture = new sf::Texture();
    Sprite = new sf::Sprite();
    Height = TileSize;
    Length = TileSize;
    Texture->loadFromFile("../Imagenes/Grass.png");//imagen es 500X500px
    Sprite->setTexture(*Texture, true);
    Sprite->setScale(Length / 500, Height / 500);
    X = 0;
    Y = 0;
}
