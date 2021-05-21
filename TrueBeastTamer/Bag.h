#pragma once
#include "GameObject.h"
#include "Beast.h"
#include "Word.h"
using namespace System::Collections::Generic;
using namespace System;
namespace GameModel {
    [Serializable]
    public ref class Bag :public GameObject {
    public:
        property List<Beast^>^ Beast;
        property sf::RectangleShape* Rect;
        property List<GameView::Word^>^ Word;
        property bool open;
    public:
        Bag();
        void setDrawables(sf::String t);
        void Draw(sf::RenderTarget& rt);
    };
}
