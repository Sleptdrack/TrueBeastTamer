#include "pch.h"
#include "Bag.h"

GameModel::Bag::Bag()
{
	Sprite = new sf::Sprite();
	Length = 500;
	Height = 500;
	Word = gcnew List<GameView::Word^>();
	GameView::Word^ w1 = gcnew GameView::Word(50, 50, "Bag", 24, sf::Color::Black);
	Word->Add(w1);
	Beast = gcnew List<GameModel::Beast^>();
	Texture = new sf::Texture();
	Texture->loadFromFile("../Imagenes/Wood.JPG");
	Sprite->setTexture(*Texture);
	Sprite->setScale(Length / Texture->getSize().x, Height / Texture->getSize().y);
	Sprite->setPosition(0, 0);
	open = false;
}

void GameModel::Bag::Draw(sf::RenderTarget& rt)
{
	rt.draw(*Sprite);
	for (int i = 0; i < Word->Count; i++) {
		Word[i]->Draw(rt);
	}
	for (int i = 0; i < Beast->Count; i++) {
		Beast[i]->Draw(rt);
	}
}
