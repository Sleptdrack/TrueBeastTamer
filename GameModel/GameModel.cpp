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

//espacio cuando se implemente Arena

GameModel::Power::Power()
{
    throw gcnew System::NotImplementedException();
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
    Texture->loadFromFile("Imagenes/Grass.png");//verificar ubicacion
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

//Espacio cuando se implemente obstaculos
//Espacios para los distintos obstaculos

GameModel::Map::Map(int ng, int nn)
{
    NumGarden = ng;
    NumNPC = nn;
    Obstacle = gcnew List<GameModel::Obstacle^>();
    Garden = gcnew List<GameModel::Garden^>();
    NPC = gcnew List<GameModel::NPC^>();
    Hospital = gcnew GameModel::Hospital(0, 0);//actualizar valores despues
    Store = gcnew GameModel::Store(0, 0);//actualizar valores
    Player = gcnew Tamer(0, 0);//actualizar valores
}


