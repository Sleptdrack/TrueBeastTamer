#pragma once
#include "GameObject.h"
#include "Beast.h"
using namespace System::Collections::Generic;
using namespace System;
namespace GameModel {
    [Serializable]
    public ref class Bag :public GameObject {
    public:
        property List<Beast^>^ Beast;
    public:
        Bag();
    };
}
