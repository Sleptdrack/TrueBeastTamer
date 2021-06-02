#include "pch.h"
#include "LogInSc.h"
#include <iostream>
GameView::LogInSc::LogInSc(){
    Screen = gcnew GameView::Screen(500,500,400,200,"Log in");
    bool slog = true;
    U = new sf::String("");
    P = new sf::String("");

    WordSource::LoadFromFile("../Path/LogScreen.txt");
    List<System::String^>^ s = gcnew List<System::String^>();
    for (int i = 0; i < WordSource::Word->Count; i++) {
        s->Clear();
        s = WordSource::Word[i];
        GameView::Word^ w = gcnew GameView::Word((float)System::Int32::Parse(s[0]),
            (float)System::Int32::Parse(s[1]),
            s[2],
            System::Int32::Parse(s[3]),
            sf::Color::Color((uint32_t)System::UInt32::Parse(s[4])));
        Screen->Add(w);
    }
    
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
    Screen->Draw();
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
            if (Screen->Word[0]->Click(*Screen->W)) {
                Screen->W->close();
                *r = false;
            }
            Fill(event);
        }
        if (Screen->Word[1]->Click(*Screen->W)) {
            T = GameController::GameManager::ValidatePlayer(Word::SFtoSys(*U), Word::SFtoSys(*P));
            
            if (T!=nullptr) {
                *r = true;
                MessageBox::Show("Welcome " + T->Username);
                Screen->W->close();
            }
            else {
                MessageBox::Show("Player not Found");
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
