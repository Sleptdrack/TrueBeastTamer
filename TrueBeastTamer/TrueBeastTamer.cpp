#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "Map.h"
#include "Movement.h"
#include "Fight.h"
#include "Interraction.h"
#include "Screen.h"
#include "LogInSc.h"
#include "Tutorial.h"
#include "PathSource.h"
#include "Pause.h" // julio
#include <iostream>
using namespace sf;
using namespace System;
using namespace GameModel;
using namespace GameView;
int main() {
    srand(time(NULL));
    float x = 50, y = 0;
    bool life=false;
    sf::Vector2f* rtv = new sf::Vector2f();
    //path
    PathSource::LoadFromFile("../Path/Path.txt");
    View View;
    Time t,t1,t2;
    Clock clk,clk2;
    Clock c1;
    RectangleShape* rec = new RectangleShape(sf::Vector2f(1920, 1080));
    //Log in screen
    while (1) {
        LogInSc^ LI = gcnew LogInSc();
        Tutorial^ TU = nullptr;
        bool ready = false, Tready = true;
        //

        //
        LI->Log(&ready);
        if (ready == false) {
            return 0;
        }
        else if (LI->T->Bag->Beast->Count == 0 && ready) {
            Tready = false;
            //Pause::Init();
            Tutorial^ TU = gcnew Tutorial(LI->T);
            TU->ChooseBeast(&Tready);
            LI->T = TU->T;
            
        }
        Arena^ A = nullptr;
        Map^ M = nullptr;
        sf::RenderWindow window;
        
        bool pause = false;
        bool pause2 = false;
        if (ready && Tready) {
            M = gcnew Map(10, 0, LI->T);
            M->Player->Move(0, 0);
            M->Player->Bag->open = false;
            M->Player->PauseObj->m_flagPause = false;
            M->Player->HealthObj->m_flagHealth = false;
           // M->Player->Pause1->LoadDraw();
            GameManager::UpdatePlayer(M->Player);
            window.create(sf::VideoMode(1920, 1080), "TrueBeastTamer"/*, sf::Style::Fullscreen*/);
            window.setSize(sf::Vector2u(PathSource::Resolution[0], PathSource::Resolution[1])); 
        }
        else {
            return 0;
        }
        while (window.isOpen())
        {
            t1 = c1.getElapsedTime();
            t = clk.getElapsedTime();
            t2 = clk2.getElapsedTime();
            clk.restart();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    GameManager::UpdatePlayer(M->Player);
                    window.close();
                }
                if (event.type == sf::Event::LostFocus) {
                    pause = true;
                }
                if (event.type == sf::Event::GainedFocus) {
                    pause = false;
                }

                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    pause2 = true;
                    M->Player->PauseObj->OpenPause(pause2);
                }
                Interraction::RenameBeast(M->Player, window, event);
            }
            if (!pause && !pause2) {
                if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                    window.close();
                }
                Movement::Move(M->Player, t, rec);
                if (t2.asMilliseconds() > 200) {

                    M->Player->Update();
                    clk2.restart();
                }
                M->Player->OpenBag();
                Interraction::SetStateBag(M->Player, window);               
                Interraction::MoveBag(M->Player, window, rtv);

                if (t1.asSeconds() > 1) {
                    Fight::Hunt(M, A, window);
                    c1.restart();
                }
                for (int i = 0; i < M->Player->Bag->Beast->Count; i++) {

                    M->Player->Bag->Beast[i]->LevelUp();               
                
                }
                if (t1.asSeconds() > 1) {
                    if (M->Hospital->Contains(M->Player))
                    {
                        if(!M->Player->HealthObj->m_flagHealth2)
                        { 
                            M->Player->HealthObj->OpenHealth(true);
                            M->Player->HealthObj->m_flagHealth2 = true;
                        }
                        
                    }
                    else
                    {
                        M->Player->HealthObj->m_flagHealth2 = false;
                    }
                }
            }
            M->Player->HealthObj->SelectOption(window,life);
            M->Player->PauseObj->SelectOption(window, pause2);
            if (life)
            {
                ;
                for (int i =0; i < M->Player->Bag->Beast->Count ;i++)
                {
                    M->Player->Bag->Beast[i]->Health[3] = M->Player->Bag->Beast[i]->Health[2];
                }
                
                life = false;
            }
            
            Interraction::MovePause(M->Player, window, rtv);
            Interraction::MoveHealth(M->Player, window, rtv);
            window.clear();
            M->Draw(window);
            window.display();
        }
    }
    return 0;
}
