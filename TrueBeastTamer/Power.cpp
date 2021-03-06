#include "pch.h"
#include "Power.h"

GameModel::Power::Power(Element t, Attack k)
{
	Type = t;
	Kind = k;
    Range = 500;
    cooldown = 1000;//en ms
    InUse = false;
    Shot = gcnew List<GameModel::Shot^>();
}
void GameModel::Power::Stop()
{
    if (InUse) {
        InUse = false;
        if (Shot->Count> 0) {
            Shot->RemoveAt(0);
        }
        Move->stop();
        Hit->stop();
    }
}
GameModel::Shot::Shot(sf::Vector2f e, sf::Vector2f s)
{
    start = new sf::Vector2f(s);
    end = new sf::Vector2f(e);
    X = start->x;
    Y = start->y;
    setDrawable(PathSource::SystoStd(PathSource::Power[0]));
}
void GameModel::Shot::setDrawable(sf::String n)
{
    Texture = new sf::Texture();
    Sprite = new sf::Sprite();
    Texture->loadFromFile(n);
    Sprite->setTexture(*Texture);
    Sprite->setPosition(X, Y);
    Sprite->setOrigin(Sprite->getGlobalBounds().width / 2, Sprite->getGlobalBounds().height / 2);
    Sprite->setScale(2, 2);
    
}
