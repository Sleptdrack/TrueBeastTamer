#pragma once
#include "GameObject.h"
#include "Power.h"
#include <cmath>
using namespace System::Collections::Generic;
using namespace System;
typedef enum {Trululu, Atropos, Quin, Mosfet} BeastName;
namespace GameModel {
    [Serializable]
    public ref class Beast : public GameObject
    {
    public:
        property BeastName Name;
        property System::String^ TagName;
        property Element Type;//Element
        property List<float>^ Health;
        property List<float>^ Defense;
        property List<float>^ Attack;
        property List<float>^ Cooldown;
        property List<Power^>^ Power;
        property int Level;
        property int Exp;

    public:
        Beast(BeastName name);//el predeterminado
        void SetDrawables(sf::String s, sf::String a1, sf::String a2);
        void Learn();
        void LevelUp();
        void UpdateStats(List<float>^ T,int L);
        //codigo de GC
        void setStat(List<float>^ s, float base, float particularidad, float radio);

    };
}
