#include "pch.h"
#include "GameObject.h"

GameModel::GameObject::GameObject(){
    X = 0;
    Y = 0;
    Sprite = new sf::Sprite();
    Texture = new sf::Texture();
}

void GameModel::GameObject::Draw(RenderTarget& rt){
    rt.draw(*Sprite);
}

void GameModel::GameObject::Move(float x, float y)
{
    Sprite->setPosition(x, y);
    X = x;
    Y = y;
}

bool GameModel::GameObject::Contains(GameObject^ G)
{
    FloatRect T = { G->X,G->Y,G->Length,G->Height };
    bool f;
    if (Sprite->getGlobalBounds().intersects(T))f = true;
    else f = false;
    return f;
}
