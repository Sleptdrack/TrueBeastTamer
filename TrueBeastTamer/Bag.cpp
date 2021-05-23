#include "pch.h"
#include "Bag.h"

GameModel::Bag::Bag()
{

	Length = 500;
	Height = 500;
	X = 0;
	Y = 0;
	Word = gcnew List<GameView::Word^>();
	GameView::Word^ w1 = gcnew GameView::Word(0, 0, "Bag", 24, sf::Color(255,101,80,255));
	w1->Move(X + Length / 2 - w1->Rect->getGlobalBounds().width/2, Y + 1 * (Height / 6) - w1->Rect->getGlobalBounds().height);
	GameView::Word^ w2 = gcnew GameView::Word(0, 0, "Items", 24, sf::Color(255, 101, 80, 255));
	w2->Move(X + 1*(Length /4) - w1->Rect->getGlobalBounds().width/2, Y + 2 * (Height / 6) - w1->Rect->getGlobalBounds().height);
	GameView::Word^ w3 = gcnew GameView::Word(0, 0, "Beasts", 24, sf::Color(255, 101, 80, 255));
	w3->Move(X +3* (Length / 4) - w3->Rect->getGlobalBounds().width/2, Y + 2 * (Height / 6) - w3->Rect->getGlobalBounds().height);
	GameView::Word^ w4 = gcnew GameView::Word(0,0, "Settings", 24, sf::Color(255, 101, 80, 255));
	w4->Move(X + Length / 2 - w4->Rect->getGlobalBounds().width/2, Y + 3 * (Height / 6) - w4->Rect->getGlobalBounds().height);
	GameView::Word^ w5 = gcnew GameView::Word(0, 0, "Save", 24, sf::Color(255, 101, 80, 255));
	w5->Move(X + Length / 2 - w5->Rect->getGlobalBounds().width/2, Y + 4 * (Height / 6) - w5->Rect->getGlobalBounds().height);
	GameView::Word^ w6 = gcnew GameView::Word(0, 0, "Log Out", 24, sf::Color(255, 101, 80, 255));
	w6->Move(X + Length / 2 - w6->Rect->getGlobalBounds().width/2, Y + 5 * (Height / 6) - w6->Rect->getGlobalBounds().height);
	Word->Add(w1);
	Word->Add(w2);
	Word->Add(w3);
	Word->Add(w4);
	Word->Add(w5);
	Word->Add(w6);
	Beast = gcnew List<GameModel::Beast^>();
	setDrawables(PathSource::SystoStd(PathSource::Bag[0]));
	open = false;
}

void GameModel::Bag::setDrawables(sf::String t){
	GameObject::setDrawables(t);
	Sprite->setColor(sf::Color(111, 29, 116, 255));
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

void GameModel::Bag::AddBeast(GameModel::Beast^ b)
{
	Beast->Add(b);
}
