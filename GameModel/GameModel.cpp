#include "pch.h"

#include "GameModel.h"

GameModel::GameObject::GameObject()
{
    
}

void GameModel::GameObject::Draw(RenderTarget& rt)
{
    rt.draw(*Sprite);
}
