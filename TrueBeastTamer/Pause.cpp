#include "pch.h"
#include "Pause.h"

void GameView::Pause::MakeWindowsOnTop(sf::RenderWindow& windows)
{
	/*HWND hwnd = windows.getSystemHandle();
	SetWindowPos*/
}

void GameView::Pause::PrintWindows(bool &pause)
{
	GameView::Word^ Message = gcnew GameView::Word(60, 30, "Paused", 30, sf::Color::Red);
	Screen = gcnew GameView::Screen(1000, 500, Message->Rect->getGlobalBounds().width + 120, 250, "Paused");
	GameView::Word^ E1 = gcnew GameView::Word(70, 80, "Resume", 24, sf::Color::Red);
	GameView::Word^ E2 = gcnew GameView::Word(70, 130, "Restart", 24, sf::Color::Red);
	GameView::Word^ E3 = gcnew GameView::Word(80, 180, "Menu", 24, sf::Color::Red);
	Screen->Add(Message);
	Screen->Add(E1);
	Screen->Add(E2);
	Screen->Add(E3);
	while (Screen->W->isOpen())
	{
		sf::Event event;
		while (Screen->W->pollEvent(event))
		{
			if (Screen->Word[0]->Click(*Screen->W)) {
				pause = false;
				Screen->W->close();
			}
			if (Screen->Word[2]->Click(*Screen->W))// resume
			{
				pause = false;
				Screen->W->close();
			}
			if (Screen->Word[3]->Click(*Screen->W)){} // reset
			if (Screen->Word[4]->Click(*Screen->W)){} // menu
		}
		Screen->W->clear();
		Screen->Draw();
		Screen->W->display();
	}
   
}
