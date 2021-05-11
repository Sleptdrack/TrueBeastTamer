#include "pch.h"
#include "Word.h"

GameView::Word::Word(float x, float y, String* T, int size, sf::Color c){
    Font = new sf::Font();
    Text = new sf::Text();
    Color = new sf::Color(c);
    SB = new sf::SoundBuffer();
    S = new sf::Sound();
    on = false;
    Size = size;
    X = x;
    Y = y;
    Font->loadFromFile("../Font/Bullpen3D.ttf");
    Text->setFont(*Font);
    Text->setString(*T);
    Text->setCharacterSize(size);
    Text->setFillColor(*Color);
    Text->setPosition(X, Y);
    Rect = new RectangleShape();
    Rect->setSize(sf::Vector2f(Text->getGlobalBounds().width+5, Text->getGlobalBounds().height+7));
    Rect->setPosition(X, Y);
    Rect->setFillColor(sf::Color::Transparent);
    SB->loadFromFile("../Sound/Click.WAV");
    S->setBuffer(*SB);
    S->setVolume(50);
}

void GameView::Word::Draw(sf::RenderTarget& rt){
    rt.draw(*Rect);
    rt.draw(*Text);
}

void GameView::Word::Move(float x, float y){
    X = x;
    Y = y;
    Text->setPosition(X, Y);
}

bool GameView::Word::Click(sf::RenderWindow& rt){
    sf::Vector2i m = sf::Mouse::getPosition(rt);
    if (Text->getGlobalBounds().contains((sf::Vector2f)m)) {
        Text->setFillColor(sf::Color::Blue);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            S->play();
            return true;
        }
    }
    else {
        Text->setFillColor(*Color);
    }
    return false;
}

void GameView::Word::UpdateString(sf::String* T)
{
    Text->setString(*T);
    Rect->setSize(sf::Vector2f(Text->getGlobalBounds().width+5, Text->getGlobalBounds().height+7));
}

void GameView::Word::RectColor(sf::Color c)
{
    Rect->setFillColor(c);
}
