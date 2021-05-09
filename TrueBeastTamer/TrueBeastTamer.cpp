#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "Map.h"
#include "Movement.h"
#include "Screen.h"
#include "LogInSc.h"
#include <iostream>
using namespace sf;
using namespace System;
using namespace GameModel;
using namespace GameController;
using namespace GameView;
int main() {
    srand(time(NULL));
    float x = 50, y = 0;
    View View;
    Time t;
    Clock clk;
    Map^ M = gcnew Map(10,0);
    //Log in screen
    LogInSc^ LI = gcnew LogInSc();
    //

    sf::RenderWindow window(sf::VideoMode(800,800), "TrueBeastTamer"/*,sf::Style::Fullscreen*/);
    while (window.isOpen())
    {

        t = clk.getElapsedTime();
        clk.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }                
            LI->Fill(event, window);
        }
        if (Keyboard::isKeyPressed(Keyboard::Enter)) {
            window.close();
        }
        //Movement::Move(P->Player, t);
        window.clear();
        //LI->Draw(window);
        M->Draw(window);
        window.display();
    }

    return 0;
}
