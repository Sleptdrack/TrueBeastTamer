#include "pch.h"
#include "GameManager.h"

Tamer^ GameController::GameManager::ValidatePlayer(sf::String u, sf::String p)
{
    Tamer^ T = nullptr;
    if (u == "cigreda" && p == "password") {
        T = gcnew Tamer(u, p);
    }
    if (u == "GC" && p == "password") {
        T = gcnew Tamer(u, p);
    }
    // agregen sus usuarios
    return T;
}
