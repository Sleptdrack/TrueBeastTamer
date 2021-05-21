#include "pch.h"
#include "Word.h"
#include <msclr\marshal_cppstd.h>
GameView::Word::Word(float x, float y, System::String^ t, int size, sf::Color c){
    T = gcnew System::String(t);
    on = false;
    Size = size;
    X = x;
    Y = y;
    Code = c.toInteger();
    SetParameters(PathSource::SystoStd(PathSource::Word[0]),PathSource::SystoStd(PathSource::Word[1]),Code);
}

void GameView::Word::SetParameters(sf::String f, sf::String a, uint32_t c)
{
    Color = new sf::Color(c);
    SB = new sf::SoundBuffer();
    S = new sf::Sound();
    Font = new sf::Font();
    Text = new sf::Text();
    Rect = new RectangleShape();
    Font->loadFromFile(f);
    Text->setFont(*Font);
    std::string st;
    Text->setString((std::string)msclr::interop::marshal_as<std::string>(T));
    Text->setCharacterSize(Size);
    Text->setFillColor(*Color);
    Text->setPosition(X, Y);
    Rect->setSize(sf::Vector2f(Text->getGlobalBounds().width + 5, Text->getGlobalBounds().height + 7));
    Rect->setPosition(X, Y);
    Rect->setFillColor(sf::Color::Transparent);
    SB->loadFromFile(a);
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

void GameView::Word::UpdateString(sf::String T)
{
    Text->setString(T);
    Rect->setSize(sf::Vector2f(Text->getGlobalBounds().width+5, Text->getGlobalBounds().height+7));
    this->T = SFtoSys(T);
}

void GameView::Word::Fill(sf::Event e,sf::String *U)
{
    if (e.type == sf::Event::TextEntered) {
        if (e.text.unicode == 8) {
            *U = (sf::String)U->substring(0, U->getSize() - 1);
        }
        else {
            if (e.key.code != Keyboard::Enter) {
                *U+=e.text.unicode;
            }
        }
        UpdateString(*U);
    }
}

void GameView::Word::RectColor(sf::Color c)
{
    Rect->setFillColor(c);
}

System::String^ GameView::Word::SFtoSys(sf::String t){
    return msclr::interop::marshal_as<System::String^>(t.toAnsiString());
}

sf::String GameView::Word::SystoSF(System::String^ t){
    
    return sf::String(msclr::interop::marshal_as<std::string>(t));
}
