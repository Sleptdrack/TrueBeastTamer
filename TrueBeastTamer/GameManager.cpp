#include "pch.h"
#include "GameManager.h"

Tamer^ GameController::GameManager::ValidatePlayer(sf::String u, sf::String p)
{
    Tamer^ T = nullptr;
    List<Tamer^>^ P = QueryPlayers();
    for (int i = 0; i < P->Count; i++) {
        if (u == *P[i]->Username && p == *P[i]->Password) {
            T = P[i];
        }
    }
    //cuando se implemente persistencia
    //eliminar la siguiente seccion
    if (u == "cigreda" && p == "password") {
        T = gcnew Tamer(u, p,1);
    }
    if (u == "GC" && p == "password") {
        T = gcnew Tamer(u, p,2);
    }
    // agregen sus usuarios
    return T;
}

List<Tamer^>^ GameController::GameManager::QueryPlayers()
{
    return Player;
}

void GameController::GameManager::AddPlayer(Tamer^ T){
    Player->Add(T);
}
