#include "pch.h"
#include "BeastHUB.h"
#include "Beast.h"

void GameView::BeastHUB::setDrawables(sf::String h, sf::String e, sf::String m) {
	expT = new sf::Texture();
	hpT = new sf::Texture();
	hubT = new sf::Texture();

	expT->loadFromFile(e);
	hpT->loadFromFile(h);
	hubT->loadFromFile(m);

	Exp = new sf::Sprite();
	Hp = new sf::Sprite();
	HUB = new sf::Sprite();

	Exp->setTexture(*expT);
	Hp->setTexture(*hpT);
	HUB->setTexture(*hubT);
}

void GameView::BeastHUB::Draw(RenderTarget& rt)
{
	rt.draw(*Hp);
	rt.draw(*Exp);
	rt.draw(*HUB);
	//dibujar palabras
}

GameView::BeastHUB::BeastHUB(float x, float y, Beast^ G)
{
	X = x;
	Y = y;
	//agregar palabras
	setDrawables("../Imagenes/hp.png", "../Imagenes/exp.png", "../Imagenes/marco.png");
	HUB->setPosition(X, Y);//modificar
	Exp->setPosition(X + 118, Y + 167);
	Hp->setPosition(X + 70, Y + 131);
	Exp->setScale(G->Exp/100, 1);
	Hp->setScale(G->Health[3] / G->Health[2], 1);
}

void GameView::BeastHUB::Update(Beast^ G)
{
	Exp->setScale(G->Exp / 100, 1);
	Hp->setScale(G->Health[3] / G->Health[2], 1);
}
