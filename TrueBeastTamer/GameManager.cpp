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
        }
    }
    // agregen sus usuarios
    return T;
}

List<Tamer^>^ GameController::GameManager::QueryPlayers()
{
    LoadPlayers();
    return Player;
}

Tamer^ GameController::GameManager::CreateTamer(System::String^ u, System::String^ p){
    Tamer^ T = nullptr;
    List<Tamer^>^ P = QueryPlayers();
    bool exist = false;
    for (int i = 0; i < P->Count; i++) {
        if (P[i]->Username->Equals(u)) {
            exist = true;
        }
    }
    if (exist) {
        //mandar mensaje de que el usuario
        //ya existe
        std::cout << "Usuario ya existe\n";
    }
    else {
        T = gcnew Tamer(u, p, P->Count+1);
        Player->Add(T);
        SavePlayers();
        //mensaje usuario creado
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
