#include "pch.h"
#include "GameObject.h"

GameObject::GameObject(){
    X = 0;
    Y = 0;
    Sprite = new sf::Sprite();
    Texture = new sf::Texture();
}

void GameObject::Draw(RenderTarget& rt){
    rt.draw(*Sprite);
}

void GameObject::Move(float x, float y)
{
    Sprite->setPosition(x, y);
    X = x;
    Y = y;
}

bool GameObject::Contains(GameObject^ G)
{
    FloatRect T = { G->X,G->Y,G->Length,G->Height };
    bool f;
    if (Sprite->getGlobalBounds().intersects(T))f = true;
    else f = false;
    return f;
}
