#include "pch.h"
#include "Screen.h"

GameView::Screen::Screen(float x, float y, float l, float h, sf::String n){
    Word = gcnew List<GameView::Word^>();
    Texture = new sf::Texture();
    X = x;
    Y = y;
    Length = l;
    Height = h;
    Rect = new sf::RectangleShape(sf::Vector2f(Length, Height));
    Rect->setFillColor(sf::Color::Transparent);
    W = new sf::RenderWindow(sf::VideoMode(Length, Height), n, sf::Style::None);
    GameView::Word^ X_ = gcnew GameView::Word(Length - 25, 0,"X", 24, sf::Color::Red);
    W->setPosition(sf::Vector2i(X,Y));
    Add(X_);
}

void GameView::Screen::Add(GameView::Word^ w)
{
    Word->Add(w);
}

void GameView::Screen::Draw()
{
    W->draw(*Rect);
    for (int i = 0; i < Word->Count; i++) {
        Word[i]->Draw(*W);
    }

}
