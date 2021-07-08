#include "pch.h"
#include "Tamer.h"

GameModel::Tamer::Tamer(System::String^ U, System::String^ P, int id/*, dummy mydummy*/)
{
    Id = id;
    Username = gcnew System::String(U);
    Password = gcnew System::String(P);
    Bag = gcnew GameModel::Bag();
    PauseObj = gcnew GameModel::Pause();
    HealthObj = gcnew GameModel::Health();
    /*
    speed = dummy.speed;
    texture = new sf::...
    Texture->loadfrom( Tamer.selectrandom( dummy.sprite, dummy.prob ) )

    damage = dummy.damage
    type = dummy.type
    ...

    */
    X = 0;
    Y = 0;
    Speed = 2;
    Length = TileSize;
    Height = TileSize;
    setDrawables(PathSource::SystoStd(PathSource::Tamer[0]));
}

void GameModel::Tamer::OpenBag(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab));
        if (Bag->open)Bag->open = false;
        else Bag->open = true;
    }
}

void GameModel::Tamer::Draw(RenderTarget& rt)
{
    rt.draw(*Sprite);
    if (Bag->open) {
        Bag->Draw(rt);
    }
    PauseObj->DrawPause(rt);
    HealthObj->DrawPause(rt);
}

bool GameModel::Tamer::Defeated()
{
    int a = 0;
    bool s;
    for (int i = 0; i < Bag->Beast->Count; i++) {

        if (Bag->Beast[i]->Health[3] <= 0) {
            a = a;
        }
        else {
            a = a + 1;
        }
    }
    if (a == 0) {
        s = true;;
    }
    else {
        s = false;
    }
    return s;
}
