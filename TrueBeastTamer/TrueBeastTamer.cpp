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
    //Log in screen
    LogInSc^ LI = gcnew LogInSc();
    bool ready = false;
    LI->Log(&ready);
    //
    Map^ M = gcnew Map(10, 0, LI->T);    
    sf::RenderWindow window;
    if (ready) {
        window.create(sf::VideoMode(800, 800), "TrueBeastTamer", sf::Style::Fullscreen);
    }
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
        }
        if (Keyboard::isKeyPressed(Keyboard::Enter)) {
            window.close();
        }
        Movement::Move(M->Player, t);
        window.clear();
        M->Draw(window);
        window.display();
    }

    return 0;
}
