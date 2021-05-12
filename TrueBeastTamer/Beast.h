#pragma once
#include "GameObject.h"
namespace GameModel {
    public ref class Beast : public GameObject
    {
    public:
        property sf::String* lName;
        property int Type;
        property int Health;
        property int Defence;
        property int Attack;
        property int Speed;
        property int Level;
        property int Exp;
    public:
        void Leam();


    };
}
