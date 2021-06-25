#include "pch.h"
#include "Stat.h"

GameView::Stat::Stat(GameModel::Beast^ B)
{
    base = new sf::ConvexShape(4);
    exent = new sf::ConvexShape(4);
    real = new sf::ConvexShape(4);
    Word = gcnew List<GameView::Word^>();
    Word->Add(gcnew GameView::Word(0, 150, "HP", 18, sf::Color::Green));
    Word->Add(gcnew GameView::Word(0, -150, "ATK", 18, sf::Color::Green));
    Word->Add(gcnew GameView::Word(-150,0, "DEF", 18, sf::Color::Green));
    Word->Add(gcnew GameView::Word(150, 0, "CLD", 18, sf::Color::Green));
    //base setup
    base->setPoint(0, sf::Vector2f(0, 50));
    base->setPoint(2, sf::Vector2f(0, -(50)));
    base->setPoint(3, sf::Vector2f(-(50), 0));
    base->setPoint(1, sf::Vector2f(+(50), 0));
    base->setFillColor(sf::Color::Transparent);
    base->setOutlineThickness(2);
    base->setOutlineColor(sf::Color::Blue);

    //exent setup
    exent->setPoint(0, sf::Vector2f(0, 50+100));
    exent->setPoint(2, sf::Vector2f(0, -(50+100)));
    exent->setPoint(3, sf::Vector2f(-(50+100), 0));
    exent->setPoint(1, sf::Vector2f(+(50+100), 0));
    exent->setFillColor(sf::Color::Transparent);
    exent->setOutlineThickness(2);
    exent->setOutlineColor(sf::Color::Blue);

    //real setup
    real->setPoint(0, sf::Vector2f(0, 50+100*B->Health[1]/B->Health[5]));
    real->setPoint(2, sf::Vector2f(0, -(50 + 100*B->Attack[1] / B->Attack[5])));
    real->setPoint(3, sf::Vector2f(-(50 + 100* B->Defense[1] / B->Defense[5]), 0));
    real->setPoint(1, sf::Vector2f(+(50 + 100* B->Cooldown[1] / B->Cooldown[5]), 0));
    real->setFillColor(sf::Color::Red);
    real->setOutlineThickness(2);
    real->setOutlineColor(sf::Color::Red);
}

void GameView::Stat::Move(float x, float y)
{
    X = x;
    Y = y;
    base->setPosition(X, Y);
    exent->setPosition(X, Y);
    real->setPosition(X, Y);

    Word[0]->Move(X-Word[0]->Rect->getGlobalBounds().width/2, Y + exent->getGlobalBounds().height / 2+5);//HP
    Word[1]->Move(X - Word[1]->Rect->getGlobalBounds().width / 2, Y -( exent->getGlobalBounds().height / 2 + Word[1]->Rect->getGlobalBounds().height/2+12));//ATK
    Word[2]->Move(X - exent->getGlobalBounds().width / 2-Word[2]->Rect->getGlobalBounds().width, Y- Word[2]->Rect->getGlobalBounds().height / 2);//DEF
    Word[3]->Move(X + (exent->getGlobalBounds().width / 2)+5, Y - Word[3]->Rect->getGlobalBounds().height / 2);//CLD
}

void GameView::Stat::Draw(sf::RenderTarget& rt)
{
    rt.draw(*real);
    rt.draw(*exent);
    rt.draw(*base);
    for (int i = 0; i < Word->Count; i++) {
        Word[i]->Draw(rt);
    }
}

void GameView::Stat::Scale(float x, float y)
{
    base->setScale(x, y);
    exent->setScale(x, y);
    real->setScale(x, y);
}
