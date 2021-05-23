#include "pch.h"
#include "Tutorial.h"

GameView::Tutorial::Tutorial(Tamer^ t)
{
	T = t;
	Screen = gcnew GameView::Screen(0, 0, 1920, 1080, (sf::String)"Tutorial");
	Beast = gcnew List<GameModel::Beast^>();
	GameModel::Beast^ b1 = gcnew GameModel::Beast(Trululu);
	GameModel::Beast^ b2 = gcnew GameModel::Beast(Atropos);
	GameModel::Beast^ b3 = gcnew GameModel::Beast(Mosfet);
	GameModel::Beast^ b4 = gcnew GameModel::Beast(Quin);
	Beast->Add(b1);
	Beast->Add(b2);
	Beast->Add(b3);
	Beast->Add(b4);
	for (int i = 0; i < Beast->Count; i++) {
		Beast[i]->Move((i + 1) * (Screen->Length / (Beast->Count + 1)) - Beast[i]->Length / 2, 200);
	}

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
		Screen->W->clear();
		Draw();
		Screen->W->display();
	}
}
