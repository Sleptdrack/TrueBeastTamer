#pragma once
#include "GameObject.h"
#include "Power.h"
#include <cmath>
using namespace System::Collections::Generic;
namespace GameModel {
    public ref class Beast : public GameObject
    {
    public:
        property sf::String* Name;
        property sf::String* TagName;
        property sf::String* Type;
        property List<float>^ Health;
        property List<float>^ Defense;
        property List<float>^ Attack;
        property List<float>^ Cooldown;
        property List<Power^>^ Power;
        property int Level;
        property int Exp;
    public:
        Beast();//el predeterminado
        void Learn();
        void LevelUp();
        void UpdateStats(List<float>^ T,int L);


    };
}
