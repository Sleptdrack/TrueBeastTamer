#pragma once
#include "GameObject.h"
namespace GameModel {
    public ref class Beast : public GameObject
    {
    public:
        property sf::String* Name;
        property sf::String* TagName;
        property int Type;
        property int Health;
        property int Defense;
        property int Attack;
        property int Speed;
        property int Level;
        property int Exp;
    public:
        Beast(float x, float y);//falta implementar
        void Learn();


    };
}
