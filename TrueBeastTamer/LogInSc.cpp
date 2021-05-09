#include "pch.h"
#include "LogInSc.h"

GameView::LogInSc::LogInSc(){
    Screen = gcnew GameView::Screen(0,0,400,400);
    bool slog = true;
    U = new sf::String("");
    P = new sf::String("");
    sf::String* w1 = new sf::String("Log in");
    sf::String* w2 = new sf::String("Sign Up");
    sf::String* w3 = new sf::String("Username");
    sf::String* w4 = new sf::String("");
    sf::String* w5 = new sf::String("Password");
    sf::String* w6 = new sf::String("");
    GameView::Word^ Login = gcnew GameView::Word(50, 300, w1, 24, sf::Color::Red);
    GameView::Word^ SignUp = gcnew GameView::Word(250, 300, w2, 24, sf::Color::Red);
    GameView::Word^ U = gcnew GameView::Word(50, 100, w3, 24, sf::Color::Red);
    GameView::Word^ U1 = gcnew GameView::Word(100, 150, w4, 24, sf::Color::Blue);
    GameView::Word^ P = gcnew GameView::Word(50, 200, w5, 24, sf::Color::Red);
    GameView::Word^ P1 = gcnew GameView::Word(100, 250, w6, 24, sf::Color::Blue);
    Screen->Add(Login);
    Screen->Add(SignUp);
    Screen->Add(U);
    Screen->Add(U1);
    Screen->Add(P);
    Screen->Add(P1);
}

void GameView::LogInSc::Fill(sf::Event e,sf::RenderWindow& w)
{
    if (Screen->Word[2]->Click(w)) {
        Screen->Word[2]->on = true;
        Screen->Word[4]->on = false;
    }
    if (Screen->Word[4]->Click(w)) {
        Screen->Word[4]->on = true;
        Screen->Word[2]->on = false;
    }
    if (Screen->Word[2]->on) {
        if (e.type == sf::Event::TextEntered) {
            if (e.text.unicode == 8) {
                *U = (sf::String)U->substring(0,U->getSize()-1);
            }
            else {
                *U += e.text.unicode;
            }
            Screen->Word[3]->UpdateString(U);
        }
    }
    if (Screen->Word[4]->on) {
        if (e.type == sf::Event::TextEntered) {
            if (e.text.unicode == 8) {
                *P = (sf::String)P->substring(0, P->getSize() - 1);
            }
            else {
                *P += e.text.unicode;
            }
            Screen->Word[5]->UpdateString(P);
        }
    }

}

void GameView::LogInSc::Draw(sf::RenderTarget& r)
{
    Screen->Draw(r);
}
