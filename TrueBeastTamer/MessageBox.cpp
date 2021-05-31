#include "pch.h"
#include "MessageBox.h"

void GameView::MessageBox::Show(System::String^ n){
	GameView::Word^ Message = gcnew GameView::Word(60, 30, n, 24, sf::Color::Red);
	Screen = gcnew GameView::Screen(1000, 500, Message->Rect->getGlobalBounds().width+120, 150, "Error");
	GameView::Word^ E2 = gcnew GameView::Word(140, 80, "Close", 24, sf::Color::Red);
	Screen->Add(Message);
	Screen->Add(E2);
	while (Screen->W->isOpen())
	{
		sf::Event event;
		while (Screen->W->pollEvent(event))
		{
			if (Screen->Word[0]->Click(*Screen->W))Screen->W->close();
			if (Screen->Word[2]->Click(*Screen->W))Screen->W->close();
		}
		Screen->W->clear();
		Screen->Draw();
		Screen->W->display();
	}
}
