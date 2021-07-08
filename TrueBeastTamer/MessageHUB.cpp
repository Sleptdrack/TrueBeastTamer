#include "pch.h"
#include "MessageHUB.h"

GameView::MessageHUB::MessageHUB(System::String^ t)
{
	Word = gcnew List<GameView::Word^>();
	setDrawables("../Imagenes/Box.png");
	Word->Add(gcnew GameView::Word(1020, 550, "Close", 24, sf::Color::Black));
	Word->Add(gcnew GameView::Word(900, 500, t, 24, sf::Color::Black));
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
	Sprite->setColor(sf::Color::White);
	Sprite->setPosition(890, 490);
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

void GameView::MessageHUB::Move(float x, float y)
{
	GameObject::Move(x, y);

	Word[0]->Move(X + Length / 2 - Word[0]->Rect->getGlobalBounds().width / 2, Y + 1 * (Height / 6) - Word[0]->Rect->getGlobalBounds().height);
	Word[1]->Move(X + Length / 2 - Word[1]->Rect->getGlobalBounds().width / 2, Y + 2 * (Height / 6) - Word[1]->Rect->getGlobalBounds().height);

	//Word_Pause[3]->Move(X + Length / 2 - Word_Pause[3]->Rect->getGlobalBounds().width / 2, Y + 4 * (Height / 6) - Word_Pause[3]->Rect->getGlobalBounds().height);

}
