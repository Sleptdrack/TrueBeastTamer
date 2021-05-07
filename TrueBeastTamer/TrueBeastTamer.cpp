#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "Map.h"
#include "Movement.h"
#include "Word.h"
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
    Map^ P = gcnew Map(10,0);
    sf::String* tst = new sf::String("Hola");
    Word^ T = gcnew Word(50,50,tst, 24, sf::Color::Red);
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
        if (T->Click(window)) {
            T->Move(T->X + 50, T->Y + 50);
        }
        window.clear();
        P->Draw(window);
        T->Draw(window);
        window.display();
    }

    return 0;
}
