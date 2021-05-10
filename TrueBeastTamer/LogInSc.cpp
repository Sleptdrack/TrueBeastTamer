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
    W = new sf::RenderWindow(sf::VideoMode(400, 400), "Log In");
}

void GameView::LogInSc::Fill(sf::Event e)
{
    if (Screen->Word[2]->Click(*W)) {
        Screen->Word[2]->on = true;
        Screen->Word[4]->on = false;
    }
    if (Screen->Word[4]->Click(*W)) {
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

void GameView::LogInSc::Draw()
{
    Screen->Draw(*W);
}

void GameView::LogInSc::Log(bool *r)
{
    sf::RenderWindow error;
    sf::String* e1 = new sf::String("Player not found");
    sf::String* e2 = new sf::String("close");
    GameView::Word^ E1 = gcnew GameView::Word(60, 30, e1, 24, sf::Color::Red);
    GameView::Word^ E2 = gcnew GameView::Word(140, 80, e2, 24, sf::Color::Red);
    while (W->isOpen())
    {
        sf::Event event;
        while (W->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                W->close();
            }
            Fill(event);
        }
        if (Keyboard::isKeyPressed(Keyboard::Enter)) {
            W->close();
        }
        if (Screen->Word[0]->Click(*W)) {
            if (*U == (sf::String)"Hola" && *P == (sf::String)"password") {
                *r = true;
                W->close();
            }
            else {
                W->setActive(false);
                error.create(sf::VideoMode(350, 150),"", sf::Style::None);
                while (error.isOpen()) {
                    if (E2->Click(error)) {
                        error.close();
                        W->setActive(true);
                    }
                    error.clear();
                    E1->Draw(error);
                    E2->Draw(error);
                    error.display();
                }
            }
        }
        W->clear();
        Draw();
        W->display();
    }
}
