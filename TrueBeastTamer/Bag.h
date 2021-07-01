#pragma once
#include "GameObject.h"
#include "Beast.h"
#include "Word.h"
#include "Stat.h"
using namespace System::Collections::Generic;
using namespace System;
typedef enum {Menu, Items, Beasts,Setting,Edit} Window_Bag;
namespace GameModel {
    [Serializable]
    public ref class Bag :public GameObject {
    public:
        property List<Beast^>^ Beast;
        property sf::RectangleShape* Rect;
        property Window_Bag State;
        property List<GameView::Word^>^ Word;
        property List<GameView::Word^>^ Word_Beast;
        property List<GameView::Word^>^ Word_Item;
        property List<GameView::Word^>^ Word_Setting;
        property List<GameView::Word^>^ Word_Edit;
        property GameView::Stat^ Stat;
        property bool open;
        property bool moving;
        property bool changing;
    public:
        Bag();
        void setDrawables(sf::String t);
        void setEditMode(int t);
        void Draw(sf::RenderTarget& rt);
        void AddBeast(GameModel::Beast^ b);
        void Move(float x, float y);
    };
}
