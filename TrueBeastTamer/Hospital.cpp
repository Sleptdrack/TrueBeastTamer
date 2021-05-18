#include "pch.h"
#include "Hospital.h"

GameModel::Hospital::Hospital(float x, float y) {
    Texture = new sf::Texture();
    Sprite = new sf::Sprite();
    Nurse = gcnew NPC();
    Texture->loadFromFile("../Imagenes/Hospital.png"); //Esta imagen es de 160 * 140
    Sprite->setTexture(*Texture, true);
    X = x;
    Y = y;
    Length = 100;
    Height = 100;
    Sprite->setScale(Length / 160, Height / 140);
    Sprite->setPosition(X, Y);
}