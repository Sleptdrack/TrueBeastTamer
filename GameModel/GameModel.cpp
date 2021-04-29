#include "pch.h"

#include "GameModel.h"

GameModel::GameObject::GameObject(){
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

GameModel::Beast::Beast(){
    Name = new sf::String();
}

GameModel::Tamer::Tamer(float x, float y){
    Username = new String();
    Password = new String();
    Bag = gcnew GameModel::Bag();
}

GameModel::Bag::Bag(){
    ListBeast = gcnew List<Beast^>();
}

GameModel::Store::Store(float x, float y){
    X = x;
    Y = y;
    Salesman = gcnew NPC();
}

GameModel::Hospital::Hospital(float x, float y) {
    X = x;
    Y = y;
    Nurse = gcnew NPC();
}

GameModel::Grass::Grass()
{
    Height = TileSize;
    Length = TileSize;
    Texture->loadFromFile("Imagenes/Grass.png");
    Sprite->setTexture(*Texture, true);
    Sprite->setScale(Length / 500, Height / 500);
    X = 0;
    Y = 0;
    
}

GameModel::Garden::Garden(float x, float y, int size)
{
    Grass = gcnew List<GameModel::Grass^>();
    X = x;
    Y = y;
    Size = size;
    for (int i = 0; i < Size; i++) {
        for (int u = 0; u < Size; u++) {
            GameModel::Grass^ gr = gcnew GameModel::Grass();
            gr->Move(i * gr->Length + X, u * gr->Height + Y);
            Grass->Add(gr);
        }
    }

}
void GameModel::Garden::Draw(RenderTarget& rt)
{
    for (int i = 0; i < Grass->Count; i++) {
        Grass[i]->Draw(rt);
    }
}
