#include "pch.h"
#include "Power.h"

GameModel::Power::Power(Element t, Attack k)
{
	Type = t;
	Kind = k;
    Range = 100;
    cooldown = 500;//en ms
    InUse = false;
    Shot = gcnew List<GameModel::Shot^>();
}
GameModel::Shot::Shot(sf::Vector2i e, sf::Vector2i s)
{
    start = new sf::Vector2i(s);
    end = new sf::Vector2i(e);
    X = start->x;
    Y = start->y;
    destiny = 0;
    setDrawable(PathSource::SystoStd(PathSource::Power[0]));
}
void GameModel::Shot::setDrawable(sf::String n)
{
    Texture = new sf::Texture();
    Sprite = new sf::Sprite();
    Texture->loadFromFile(n);
    Sprite->setTexture(*Texture);
    Sprite->setPosition(X, Y);
    Sprite->setScale(2, 2);
    Sprite->setOrigin(Sprite->getGlobalBounds().width / 2, Sprite->getGlobalBounds().height / 2);
}
