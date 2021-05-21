#include "pch.h"
#include "GameManager.h"
#include <iostream>
Tamer^ GameController::GameManager::ValidatePlayer(System::String^ u, System::String^ p)
{
    Tamer^ T = nullptr;
    List<Tamer^>^ P = QueryPlayers();
    if (u != "" && p != "") {
        for (int i = 0; i < P->Count; i++) {
            if (P[i]->Username->Equals(u) && P[i]->Password->Equals(p)) {
                T =P[i];
            }
            else if (P[i]->Username->Equals(u)) {
                GameView::MessageBox::Show("Wrong Password");
            }
        }
    }
    // agregen sus usuarios
    return T;
}

List<Tamer^>^ GameController::GameManager::QueryPlayers()
{
    LoadPlayers();
    for (int i = 0; i < Player->Count; i++) {
        Player[i]->setDrawables("../Imagenes/Tamer.png");
        Player[i]->Bag->setDrawables("../Imagenes/Tamer.png");
    }
    return Player;
}

Tamer^ GameController::GameManager::CreateTamer(System::String^ u, System::String^ p){
    Tamer^ T = nullptr;
    List<Tamer^>^ P = QueryPlayers();
    bool exist = false;
    if (u != "" && p != "") {
        for (int i = 0; i < P->Count; i++) {
            if (P[i]->Username->Equals(u)) {
                exist = true;
            }
        }
        if (exist) {
            GameView::MessageBox::Show("Username is taken");
        }
        else {
            T = gcnew Tamer(u, p, P->Count + 1);
            Player->Add(T);
            SavePlayers();
            GameView::MessageBox::Show("Account Created");
            //mensaje usuario creado
        }
    }
    else {
        GameView::MessageBox::Show("Invalid Arguments");
    }
    return T;
}

void GameController::GameManager::AddPlayer(Tamer^ T){
    Player->Add(T);
    SavePlayers();
}

void GameController::GameManager::SavePlayers()
{
    Stream^ stream = File::Open("player.bin", FileMode::Create);
    BinaryFormatter^ bFormatter = gcnew BinaryFormatter();
    bFormatter->Serialize(stream, Player);
    stream->Close();
}

void GameController::GameManager::LoadPlayers()
{
    if (File::Exists("player.bin")) {
        Stream^ stream = File::Open("player.bin", FileMode::Open);
        BinaryFormatter^ bFormatter = gcnew BinaryFormatter();
        Player = (List <Tamer^>^) bFormatter->Deserialize(stream);
        stream->Close();
    }
}
