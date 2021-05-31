#pragma once
#include "GameObject.h"
#include "Beast.h"
#include "Word.h"
using namespace System::Collections::Generic;
using namespace System;
typedef enum {Menu, Items, Beasts,Setting} Window_Bag;
namespace GameModel {
    [Serializable]
    public ref class Bag :public GameObject {
    public:
        property List<Beast^>^ Beast;
        property sf::RectangleShape* Rect;
        property Window_Bag State;
        property List<GameView::Word^>^ Word;
        property List<GameView::Word^>^ Word_Beast;
        property bool open;
    public:
        Bag();
        void setDrawables(sf::String t);
        void Draw(sf::RenderTarget& rt);
        void AddBeast(GameModel::Beast^ b);
    };
}
