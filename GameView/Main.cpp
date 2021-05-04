#include <SFML/Graphics.hpp>
#include<time.h>
#include <iostream>
using namespace System;
using namespace sf;
using namespace GameModel;
using namespace GameController;

int Main() {
    srand(time(NULL));
    float x = 50, y = 0;
    Map^ P = gcnew Map(10,0);
    Time t;
    Clock clk;
    sf::RenderWindow window(sf::VideoMode(600,200), "TrueBeastTamer"/*, sf::Style::Fullscreen*/);
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