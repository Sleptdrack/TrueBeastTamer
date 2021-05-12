#include "pch.h"
#include "LogInSc.h"

GameView::LogInSc::LogInSc(){
    Screen = gcnew GameView::Screen(0,0,400,200);
    bool slog = true;
    U = new sf::String("");
    P = new sf::String("");

    GameView::Word^ Login = gcnew GameView::Word(50, 125, (sf::String)"Log in", 24, sf::Color::Red);
    GameView::Word^ SignUp = gcnew GameView::Word(250, 125, (sf::String)"Sign Up", 24, sf::Color::Red);
    GameView::Word^ U = gcnew GameView::Word(50, 25, (sf::String)"Username", 24, sf::Color::Red);
    GameView::Word^ U1 = gcnew GameView::Word(U->Rect->getGlobalBounds().width+50+20, 25, (sf::String)"", 24, sf::Color::Blue);
    GameView::Word^ P = gcnew GameView::Word(50, 75, (sf::String)"Password", 24, sf::Color::Red);
    GameView::Word^ P1 = gcnew GameView::Word(P->Rect->getGlobalBounds().width+50+20, 75, (sf::String)"", 24, sf::Color::Blue);
    Screen->Add(Login);
    Screen->Add(SignUp);
    Screen->Add(U);
    Screen->Add(U1);
    Screen->Add(P);
    Screen->Add(P1);
    W = new sf::RenderWindow(sf::VideoMode(Screen->Length, Screen->Height), "Log In");
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
        Screen->Word[3]->Fill(e,U);
    }
    if (Screen->Word[4]->on) {
        Screen->Word[5]->Fill(e, P);
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
    sf::String* e3 = new sf::String("Wrong Password");
    GameView::Word^ E1 = gcnew GameView::Word(60, 30, (sf::String)"", 24, sf::Color::Red);
    GameView::Word^ E2 = gcnew GameView::Word(140, 80, (sf::String)"Close", 24, sf::Color::Red);
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
        if (Screen->Word[0]->Click(*W)) {
            if (*U == (sf::String)"Hola" && *P == (sf::String)"password") {
                *r = true;
                W->close();
            }
            else {
                if (*U == (sf::String)"Hola") {
                    E1->UpdateString(*e3);
                }
                else {
                    E1->UpdateString(*e1);
                }
                W->setActive(false);
                error.create(sf::VideoMode(350, 150),"", sf::Style::None);
                while (error.isOpen()) {
                    if (E2->Click(error)) {
                        *U = (sf::String)"";
                        *P = (sf::String)"";
                        Screen->Word[3]->UpdateString(*U);
                        Screen->Word[5]->UpdateString(*P);
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
        if (Screen->Word[1]->Click(*W)) {
            //check if username already taken
            //create new user
        }
        W->clear();
        Draw();
        W->display();
    }
}
