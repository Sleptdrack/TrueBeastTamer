#pragma once
#include "GameObject.h"
#include "Beast.h"
using namespace System::Collections::Generic;
namespace GameModel {
    public ref class Bag :public GameObject {
    public:
        property List<Beast^>^ Beast;
    public:
        Bag();
    };
}
