#pragma once
#include "GameObject.h"
namespace GameModel {
    public ref class Beast : public GameObject
    {
    public:
        String* lName;
        int Type;
        int Health;
        int Defence;
        int Attack;
        int Speed;
        int Level;
        int Exp;
    public:
        void Leam();


    };
}
