#pragma once
#include "GameObject.h"
#include "Power.h"
#include <cmath>
using namespace System::Collections::Generic;
typedef enum {Water,Fire,Air,Ligthing,Earth,Neutral} Element;
namespace GameModel {
    public ref class Beast : public GameObject
    {
    public:
        property sf::String* Name;
        property sf::String* TagName;
        property Element Type;//eliminar y reemplazar por element
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
