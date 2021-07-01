#include "pch.h"
#include "GameObject.h"

GameModel::GameObject::GameObject() 
{
    X = 0;
    Y = 0;
    FrameSize = 96;
    Sprite = new sf::Sprite();
    Texture = new sf::Texture();
    CurrentAnimation = AnimationIndex::Idle;//Cambiar Idle
   
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

void GameModel::GameObject::setDrawables(sf::String n)
{
    Texture = new sf::Texture();
    Sprite = new sf::Sprite();
    Texture->loadFromFile(n);
    Sprite->setTexture(*Texture);
    Animation = gcnew List<Animate^>();
    //Agregar el resto de estados, en orden
    Animation->Add(gcnew Animate(0, 0, FrameSize, FrameSize));//Right
    Animation->Add(gcnew Animate(0, FrameSize, FrameSize, FrameSize));//Left
    Animation->Add(gcnew Animate(0, 2 * FrameSize, FrameSize, FrameSize));//Down
    Animation->Add(gcnew Animate(0, 3 * FrameSize, FrameSize, FrameSize));//Up
    Animation->Add(gcnew Animate(0, 0, FrameSize, FrameSize, 1));//Idle
    In_Rect = new sf::IntRect(
        Animation[CurrentAnimation]->frame[Animation[CurrentAnimation]->iFrame]->X,
        Animation[CurrentAnimation]->frame[Animation[CurrentAnimation]->iFrame]->Y,
        Animation[CurrentAnimation]->frame[Animation[CurrentAnimation]->iFrame]->Width,
        Animation[CurrentAnimation]->frame[Animation[CurrentAnimation]->iFrame]->Height);
    Sprite->setTextureRect(*In_Rect);
    Sprite->setScale(Length / FrameSize, Height / FrameSize);
    Sprite->setPosition(X, Y);
}

void GameModel::GameObject::Update()
{
    Animation[CurrentAnimation]->Advance();
    Sprite->setTextureRect(sf::IntRect(
        Animation[CurrentAnimation]->frame[Animation[CurrentAnimation]->iFrame]->X,
        Animation[CurrentAnimation]->frame[Animation[CurrentAnimation]->iFrame]->Y,
        Animation[CurrentAnimation]->frame[Animation[CurrentAnimation]->iFrame]->Width,
        Animation[CurrentAnimation]->frame[Animation[CurrentAnimation]->iFrame]->Height));
}