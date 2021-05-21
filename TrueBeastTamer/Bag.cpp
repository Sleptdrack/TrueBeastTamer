#include "pch.h"
#include "Bag.h"

GameModel::Bag::Bag()
{
	Rect = new sf::RectangleShape(sf::Vector2f(500, 500));

	Word = gcnew List<GameView::Word^>();
	GameView::Word^ w1 = gcnew GameView::Word(50, 50, "Bag", 24, sf::Color::Black);
	Beast = gcnew List<GameModel::Beast^>();
	Texture = new sf::Texture();
	Texture->loadFromFile("../Imagenes/Wood.jpg");
	Rect->setTexture(Texture);
	Rect->setPosition(0, 0);
	open = false;
}

void GameModel::Bag::Draw(sf::RenderTarget& rt)
{
	rt.draw(*Rect);
	for (int i = 0; i < Word->Count; i++) {
		Word[i]->Draw(rt);
	}
	for (int i = 0; i < Beast->Count; i++) {
		Beast[i]->Draw(rt);
	}
}
