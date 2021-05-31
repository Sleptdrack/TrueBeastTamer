#include "pch.h"
#include "Bag.h"

GameModel::Bag::Bag()
{

	Length = 500;
	Height = 500;
	X = 0;
	Y = 0;
	Word = gcnew List<GameView::Word^>();
	//State Menu
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

	//State Beasts
	Beast = gcnew List<GameModel::Beast^>();
	Word_Beast = gcnew List<GameView::Word^>();
	GameView::Word^ B1 = gcnew GameView::Word(0, 0, "Beasts", 24, sf::Color(255, 101, 80, 255));
	B1->Move(X + Length / 2 - B1->Rect->getGlobalBounds().width / 2, Y + 1 * (Height / 6) - B1->Rect->getGlobalBounds().height);
	Word_Beast->Add(B1);
	setDrawables(PathSource::SystoStd(PathSource::Bag[0]));
	open = false;
	State = Window_Bag::Menu;
}

void GameModel::Bag::setDrawables(sf::String t){
	GameObject::setDrawables(t);
	Sprite->setColor(sf::Color(111, 29, 116, 255));
	for (int i=0; i < Word->Count; i++) {
		Word[i]->SetParameters(PathSource::SystoStd(PathSource::Word[0]), PathSource::SystoStd(PathSource::Word[1]), Word[i]->Code);
	}
	for (int i = 0; i < Word_Beast->Count; i++) {
		Word_Beast[i]->SetParameters(PathSource::SystoStd(PathSource::Word[0]), PathSource::SystoStd(PathSource::Word[1]), Word_Beast[i]->Code);
	}
	for (int i = 0; i < Beast->Count; i++) {
		Beast[i]->setDrawables(PathSource::SystoStd(PathSource::Beast[Beast[i]->Type]));
	}
}

void GameModel::Bag::Draw(sf::RenderTarget& rt)
{
	switch (State) {
	case Window_Bag::Menu:
		rt.draw(*Sprite);
		for (int i = 0; i < Word->Count; i++) {
			Word[i]->Draw(rt);
		}
		break;
	case Window_Bag::Beasts:
		rt.draw(*Sprite);
		Word_Beast[0]->Draw(rt);
		for (int i = 0; i < Beast->Count; i++) {
			//revisar posicion
			Beast[i]->Move(X, Y + Word_Beast[0]->Rect->getGlobalBounds().height + (i + 2) * (Height / 6));
			Beast[i]->Draw(rt);
		}
		for (int i = 1; i < Word_Beast->Count; i++) {
			//revisar posicion
			Word_Beast[i]->Move(X+Beast[i-1]->Length+20, Y + Word_Beast[0]->Rect->getGlobalBounds().height + (i + 2) * (Height / 6));
			Word_Beast[i]->Draw(rt);
		}


	}
}

void GameModel::Bag::AddBeast(GameModel::Beast^ b)
{
	Beast->Add(b);
	GameView::Word^ n = gcnew GameView::Word(Beast[Beast->Count - 1]->X + Beast[Beast->Count - 1]->Length + 20, Beast[Beast->Count - 1]->Y, Beast[Beast->Count - 1]->TagName, 24, sf::Color::Red);
	Word_Beast->Add(n);
}


