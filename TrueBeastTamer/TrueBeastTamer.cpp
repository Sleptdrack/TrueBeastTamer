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
#include <iostream>
using namespace sf;
using namespace System;
using namespace GameModel;
using namespace GameController;
using namespace GameView;
int main() {
    srand(time(NULL));
    float x = 50, y = 0;
    //path
    PathSource::LoadFromFile("../Path/Path.txt");
    View View;
    Time t,t1;
    Clock clk;
    Clock c1;
    RectangleShape* rec = new RectangleShape(sf::Vector2f(1920, 1080));
    //Log in screen
    while (1) {
        LogInSc^ LI = gcnew LogInSc();
        Tutorial^ TU = nullptr;
        bool ready = false, Tready = true;
        LI->Log(&ready);
        if (ready == false) {
            return 0;
        }
        else if (LI->T->Bag->Beast->Count == 0 && ready) {
            Tready = false;
            Tutorial^ TU = gcnew Tutorial(LI->T);
            TU->ChooseBeast(&Tready);
            LI->T = TU->T;
        }
        Arena^ A = nullptr;
        Map^ M = nullptr;
        sf::RenderWindow window;
        bool pause = false;
        if (ready && Tready) {
            M = gcnew Map(10, 0, LI->T);
            M->Player->Move(0, 0);
            M->Player->Bag->open = false;
            GameManager::UpdatePlayer(M->Player);
            window.create(sf::VideoMode(800, 800), "TrueBeastTamer"/*, sf::Style::Fullscreen*/);
        }
        else {
            return 0;
        }
        while (window.isOpen())
        {
            t1 = c1.getElapsedTime();
            t = clk.getElapsedTime();
            clk.restart();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::LostFocus) {
                    pause = true;
                }
                if (event.type == sf::Event::GainedFocus) {
                    pause = false;
                }
            }
            if (!pause) {
                if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                    window.close();
                }
                Movement::Move(M->Player, t, rec);
                M->Player->OpenBag();
                Interraction::SetStateBag(M->Player, window);
                if (t1.asSeconds() > 1) {
                    Fight::Hunt(M, A, window);
                    c1.restart();
                }
            }
            window.clear();
            M->Draw(window);
            window.display();
        }
    }
    return 0;
}
