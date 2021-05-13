#include "pch.h"
#include "LogInSc.h"

GameView::LogInSc::LogInSc(){
    Screen = gcnew GameView::Screen(0,0,400,200,"Log in");
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
    
}

void GameView::LogInSc::Fill(sf::Event e)
{
    if (Screen->Word[3]->Click(*Screen->W)) {
        Screen->Word[3]->on = true;
        Screen->Word[5]->on = false;
    }
    if (Screen->Word[5]->Click(*Screen->W)) {
        Screen->Word[5]->on = true;
        Screen->Word[3]->on = false;
    }
    if (Screen->Word[3]->on) {
        Screen->Word[4]->Fill(e,U);
    }
    if (Screen->Word[5]->on) {
        Screen->Word[6]->Fill(e, P);
    }

}

void GameView::LogInSc::Draw()
{
    Screen->Draw(*Screen->W);
}

void GameView::LogInSc::Log(bool *r)
{
    sf::RenderWindow error;
    sf::String* e1 = new sf::String("Player not found");
    sf::String* e3 = new sf::String("Wrong Password");
    GameView::Word^ E1 = gcnew GameView::Word(60, 30, (sf::String)"", 24, sf::Color::Red);
    GameView::Word^ E2 = gcnew GameView::Word(140, 80, (sf::String)"Close", 24, sf::Color::Red);
    while (Screen->W->isOpen())
    {
        sf::Event event;
        while (Screen->W->pollEvent(event))
        {
            if (Screen->Word[0]->Click(*Screen->W))Screen->W->close();
            Fill(event);
        }
        if (Screen->Word[1]->Click(*Screen->W)) {
            T = GameController::GameManager::ValidatePlayer(*U, *P);
            if (T!=nullptr) {
                *r = true;
                Screen->W->close();
            }
            else {
                E1->UpdateString(*e1);
                Screen->W->setActive(false);
                error.create(sf::VideoMode(350, 150),"", sf::Style::None);
                while (error.isOpen()) {
                    if (E2->Click(error)) {
                        *U = (sf::String)"";
                        *P = (sf::String)"";
                        Screen->Word[4]->UpdateString(*U);
                        Screen->Word[6]->UpdateString(*P);
                        error.close();
                        Screen->W->setActive(true);
                    }
                    error.clear();
                    E1->Draw(error);
                    E2->Draw(error);
                    error.display();
                }
            }
        }
        if (Screen->Word[2]->Click(*Screen->W)) {
            //check if username already taken
            //create new user
        }
        Screen->W->clear();
        Draw();
        Screen->W->display();
    }
}
