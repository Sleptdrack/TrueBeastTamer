#include "pch.h"
#include "Screen.h"

GameView::Screen::Screen(float x, float y, float l, float h){
    Word = gcnew List<GameView::Word^>();
    X = x;
    Y = y;
    Length = l;
    Height = h;
    Rect = new sf::RectangleShape(sf::Vector2f(Length, Height));
    Rect->setFillColor(sf::Color::Green);
}

void GameView::Screen::Add(GameView::Word^ w)
{
    Word->Add(w);
}

void GameView::Screen::Draw(RenderTarget& rt)
{
    rt.draw(*Rect);
    for (int i = 0; i < Word->Count; i++) {
        Word[i]->Draw(rt);
    }

}
