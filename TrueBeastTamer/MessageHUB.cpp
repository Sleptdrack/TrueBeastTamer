#include "pch.h"
#include "MessageHUB.h"

GameView::MessageHUB::MessageHUB(System::String^ t)
{
	Word = gcnew List<GameView::Word^>();
	setDrawables("../Imagenes/Box.png");
	Word->Add(gcnew GameView::Word(0, 50, "Close", 24, sf::Color::Red));
	Word->Add(gcnew GameView::Word(0, 0, t, 24, sf::Color::Red));
	Width = Word[1]->Rect->getGlobalBounds().width + 20;
	Heigth = 100;
	Sprite->setScale(Width / Texture->getSize().x, Heigth / Texture->getSize().y);
}

void GameView::MessageHUB::setDrawables(sf::String t)
{
	Texture = new sf::Texture();
	Sprite = new sf::Sprite();
	Texture->loadFromFile(t);
	Sprite->setTexture(*Texture);
	Sprite->setColor(sf::Color::Cyan);
}

void GameView::MessageHUB::Stay(bool* p, RenderWindow& rt)
{
	if (Word[0]->Click(rt)) {
		*p = false;
	}
	else *p = true;
}

void GameView::MessageHUB::Draw(RenderTarget& rt)
{
	rt.draw(*Sprite);
	for (int i = 0; i < Word->Count; i++) {
		Word[i]->Draw(rt);
	}
}

