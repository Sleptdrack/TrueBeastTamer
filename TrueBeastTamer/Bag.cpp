#include "pch.h"
#include "Bag.h"

GameModel::Bag::Bag()
{

	Length = 500;
	Height = 500;
	X = 0;
	Y = 0;
	Word = gcnew List<GameView::Word^>();
	GameView::Word^ w1 = gcnew GameView::Word(50, 50, "Bag", 24, sf::Color::Black);
	Word->Add(w1);
	Beast = gcnew List<GameModel::Beast^>();
	setDrawables(PathSource::SystoStd(PathSource::Bag[0]));
	open = false;
}

void GameModel::Bag::setDrawables(sf::String t){
	GameObject::setDrawables(t);
	for (int i=0; i < Word->Count; i++) {
		Word[i]->SetParameters(PathSource::SystoStd(PathSource::Word[0]), PathSource::SystoStd(PathSource::Word[1]), Word[i]->Code);
	}
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
