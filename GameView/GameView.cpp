#include "pch.h"
#include <SFML/Graphics.hpp>
#include<time.h>
#include <iostream>
using namespace System;
using namespace sf;
using namespace GameModel;
using namespace GameController;

int main(array<System::String^>^ args) {
    srand(time(NULL));
    float x = 50, y = 0;
    Map^ P = gcnew Map(10, 0);
    Time t;
    Clock clk;
    Garden^ G = gcnew Garden(100, 100, 3);
    sf::RenderWindow window(sf::VideoMode(600, 200), "TrueBeastTamer"/*, sf::Style::Fullscreen*/);
    while (window.isOpen())
    {
        t = clk.getElapsedTime();
        clk.restart();
        //window.setView(View);
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
        //P->Draw(window);
        window.display();
    }

    return 0;
}
