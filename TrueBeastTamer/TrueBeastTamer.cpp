#include "pch.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "Map.h"
using namespace sf;
using namespace System;
int main() {
    float x = 50, y = 0;
    View View;
    Time t;
    Clock clk;
    Texture T;
    Map^ P = gcnew Map(10,0);
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!"/*,sf::Style::Fullscreen*/);
    while (window.isOpen())
    {
        t = clk.getElapsedTime();
        clk.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Enter)) {
            window.close();
        }
        //Movement::Move(P->Player, t);
        window.clear();
        P->Draw(window);
        window.display();
    }

    return 0;
}
