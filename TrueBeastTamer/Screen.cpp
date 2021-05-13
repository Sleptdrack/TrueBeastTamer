#include "pch.h"
#include "Screen.h"

GameView::Screen::Screen(float x, float y, float l, float h, sf::String n){
    Word = gcnew List<GameView::Word^>();
    Texture = new sf::Texture();
    //Texture->loadFromFile("../Imagenes/Wood.JPG");
    X = x;
    Y = y;
    Length = l;
    Height = h;
    Rect = new sf::RectangleShape(sf::Vector2f(Length, Height));
    //Rect->setTexture(Texture);
    Rect->setFillColor(sf::Color::Transparent);
    W = new sf::RenderWindow(sf::VideoMode(Length, Height), n, sf::Style::None);
    GameView::Word^ X = gcnew GameView::Word(Length - 25, 0, (sf::String)"X", 24, sf::Color::Red);
    Add(X);
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
