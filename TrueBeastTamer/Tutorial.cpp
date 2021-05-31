#include "pch.h"
#include "Tutorial.h"

GameView::Tutorial::Tutorial(Tamer^ t)
{
	T = t;
	Screen = gcnew GameView::Screen(0, 0, 1920, 1080, (sf::String)"Tutorial");
	//Presentacion Beast
	Beast = gcnew List<GameModel::Beast^>();
	for (int i = 0; i < 4; i++) {
		GameModel::Beast^ b1 = gcnew GameModel::Beast(static_cast<BeastName>(i));
		Beast->Add(b1);
		GameView::Word^ w = gcnew GameView::Word(0, 0, Beast[i]->TagName, 24, sf::Color::Red);
		Screen->Word->Add(w);
		Beast[i]->Move((i + 1) * (Screen->Length / (4 + 1)) - Beast[i]->Length / 2, 200);
		Screen->Word[i+1]->Move(Beast[i]->X-Screen->Word[i+1]->Rect->getGlobalBounds().width/2+Beast[i]->Length/2, Beast[i]->Y + Beast[i]->Height);	
	}
	//Presentacion Word
	GameView::Word^ w = gcnew GameView::Word(0, 0, "Choose your Beast", 48, sf::Color::Red);
	Screen->Word->Add(w);
	Screen->Word[5]->Move(Screen->Length / 2 - Screen->Word[5]->Rect->getGlobalBounds().width / 2, 100);


}

void GameView::Tutorial::Draw()
{
	Screen->Draw();
	for (int i = 0; i < Beast->Count; i++) {
		Beast[i]->Draw(*Screen->W);
	}
	T->Draw(*Screen->W);
}

void GameView::Tutorial::ChooseBeast(bool* t)
{
	while (Screen->W->isOpen()) {
		sf::Event event;
		while (Screen->W->pollEvent(event))
		{
			if (Screen->Word[0]->Click(*Screen->W)) {
				Screen->W->close();
				*t = true;
			}
		}
		for (int i = 1; i < Beast->Count + 1; i++) {
			if (Screen->Word[i]->Click(*Screen->W)) {
				T->Bag->AddBeast(Beast[i - 1]);
				Screen->W->close();
				*t = true;
			}
		}
		Screen->W->clear();
		Draw();
		Screen->W->display();
	}
}
