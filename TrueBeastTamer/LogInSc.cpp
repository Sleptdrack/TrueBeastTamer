#include "pch.h"
#include "LogInSc.h"
#include <iostream>
GameView::LogInSc::LogInSc(){
    Screen = gcnew GameView::Screen(0,0,400,200,"Log in");
    bool slog = true;
    U = new sf::String("");
    P = new sf::String("");
    GameView::Word^ Login = gcnew GameView::Word(50, 125,"Log in", 24, sf::Color::Red);
    GameView::Word^ SignUp = gcnew GameView::Word(250, 125,"Sign Up", 24, sf::Color::Red);
    GameView::Word^ Ut = gcnew GameView::Word(50, 25,"Username", 24, sf::Color::Red);
    GameView::Word^ U1 = gcnew GameView::Word(Ut->Rect->getGlobalBounds().width+50+20, 25,"", 24, sf::Color::Blue);
    GameView::Word^ Pt = gcnew GameView::Word(50, 75,"Password", 24, sf::Color::Red);
    GameView::Word^ P1 = gcnew GameView::Word(Pt->Rect->getGlobalBounds().width+50+20, 75,"", 24, sf::Color::Blue);
    Screen->Add(Login);
    Screen->Add(SignUp);
    Screen->Add(Ut);
    Screen->Add(U1);
    Screen->Add(Pt);
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
    System::String^ e1 =gcnew System::String("Player not found");
    System::String^ e3 = gcnew System::String("Wrong Password");
    GameView::Word^ E1 = gcnew GameView::Word(60, 30,e1, 24, sf::Color::Red);
    GameView::Word^ E2 = gcnew GameView::Word(140, 80,"Close", 24, sf::Color::Red);
    while (Screen->W->isOpen()){
        sf::Event event;
        while (Screen->W->pollEvent(event))
        {
            if (Screen->Word[0]->Click(*Screen->W))Screen->W->close();
            Fill(event);
        }
        if (Screen->Word[1]->Click(*Screen->W)) {
            T = GameController::GameManager::ValidatePlayer(Word::SFtoSys(*U), Word::SFtoSys(*P));
            
            if (T!=nullptr) {
                *r = true;
                Screen->W->close();
            }
            else {
                //E1->UpdateString(*e1);
                Screen->W->setActive(false);
                error.create(sf::VideoMode(350, 150),"", sf::Style::None);
                while (error.isOpen()) {
                    if (E2->Click(error)) {
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
            T = GameController::GameManager::CreateTamer(Word::SFtoSys(*U), Word::SFtoSys(*P));
            if (T != nullptr) {
                *r = true;
                Screen->W->close();
            }
        }
        Screen->W->clear();
        Draw();
        Screen->W->display();
    }
}
