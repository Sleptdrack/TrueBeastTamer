#include "pch.h"
#include "Pause.h"


//void GameModel::Pause::PrintWindows(bool &pause)
//{
	//GameView::Word^ Message = gcnew GameView::Word(60, 30, "Paused", 30, sf::Color::Red);
	//Screen = gcnew GameView::Screen(1000, 500, Message->Rect->getGlobalBounds().width + 120, 250, "Paused");
	//GameView::Word^ E1 = gcnew GameView::Word(70, 80, "Resume", 24, sf::Color::Red);
	//GameView::Word^ E2 = gcnew GameView::Word(70, 130, "Restart", 24, sf::Color::Red);
	//GameView::Word^ E3 = gcnew GameView::Word(80, 180, "Menu", 24, sf::Color::Red);
	//Screen->Add(Message);
	//Screen->Add(E1);
	//Screen->Add(E2);
	//Screen->Add(E3);
	//while (Screen->W->isOpen())
	//{
	//	sf::Event event;
	//	while (Screen->W->pollEvent(event))
	//	{
	//		if (Screen->Word[0]->Click(*Screen->W)) {
	//			pause = false;
	//			Screen->W->close();
	//		}
	//		if (Screen->Word[2]->Click(*Screen->W))// resume
	//		{
	//			pause = false;
	//			Screen->W->close();
	//		}
	//		if (Screen->Word[3]->Click(*Screen->W)){} // reset
	//		if (Screen->Word[4]->Click(*Screen->W)){} // menu
	//	}
	//	Screen->W->clear();
	//	Screen->Draw();
	//	Screen->W->display();
	//}
   
//}

GameModel::Pause::Pause()
{
	Length = 250;
	Height = 300;
	X = 250;
	Y = 250;

	Word_Pause = gcnew List<GameView::Word^>();
	GameView::Word^ Message = gcnew GameView::Word(0, 0, "Game Paused", 31, sf::Color(195, 155, 105, 255));
	Message->Move(X + Length / 2 - Message->Rect->getGlobalBounds().width / 2, Y + 1 * (Height / 6) - Message->Rect->getGlobalBounds().height);

	GameView::Word^ E1 = gcnew GameView::Word(0, 0, "Resume", 28, sf::Color(240, 240, 240, 255));
	E1->Move(X + Length / 2 - E1->Rect->getGlobalBounds().width / 2, Y + 3 * (Height / 6) - E1->Rect->getGlobalBounds().height);

	GameView::Word^ E2 = gcnew GameView::Word(0, 0, "Quit", 28, sf::Color(240, 240, 240, 255));
	E2->Move(X + Length / 2 - E2->Rect->getGlobalBounds().width / 2, Y + 4 * (Height / 6) - E2->Rect->getGlobalBounds().height);

	//GameView::Word^ E3 = gcnew GameView::Word(0, 0, "Menu", 28, sf::Color(240, 240, 240, 255));
	//E3->Move(X + Length / 2 - E3->Rect->getGlobalBounds().width / 2, Y + 5 * (Height / 6) - E3->Rect->getGlobalBounds().height);

	Word_Pause->Add(Message);
	Word_Pause->Add(E1);
	Word_Pause->Add(E2);
	//Word_Pause->Add(E3);
	setDrawables(PathSource::SystoStd(PathSource::Bag[0]));
}

void GameModel::Pause::setDrawables(sf::String t)
{
	GameObject::setDrawables(PathSource::SystoStd(PathSource::Bag[0]));
	Rect = new RectangleShape(sf::Vector2f(Length/2, Height / 25));
	Rect->setPosition(X, Y);
	Sprite->setColor(sf::Color(68, 66, 59, 255));
	for (int i = 0; i < Word_Pause->Count; i++) {
		Word_Pause[i]->SetParameters(PathSource::SystoStd(PathSource::Word[0]),Word_Pause[i]->Code);
	}
}

void GameModel::Pause::OpenPause(bool pause)
{
	m_flagPause = true;
}

void GameModel::Pause::SelectOption(RenderWindow& rt, bool& pause)
{
	if (m_flagPause == true) {
		if (Word_Pause[1]->Click(rt)) {

			pause = false;
			m_flagPause = false;
		}
		if (Word_Pause[2]->Click(rt))// resume
		{
			rt.close();
			pause = false;
			m_flagPause = false;
		}
	}
}
void GameModel::Pause::DrawPause(sf::RenderTarget& rt)
{
	if (m_flagPause ==true) {
		rt.draw(*Sprite);
		for (int i = 0; i < Word_Pause->Count; i++) {
			Word_Pause[i]->Draw(rt);
		}
	}
}

void GameModel::Pause::Move(float x, float y)
{
	GameObject::Move(x, y);

	Word_Pause[0]->Move(X + Length / 2 - Word_Pause[0]->Rect->getGlobalBounds().width / 2, Y + 1 * (Height / 6) - Word_Pause[0]->Rect->getGlobalBounds().height);
	Word_Pause[1]->Move(X + Length / 2 - Word_Pause[1]->Rect->getGlobalBounds().width / 2, Y + 2 * (Height / 6) - Word_Pause[1]->Rect->getGlobalBounds().height);
	Word_Pause[2]->Move(X + Length / 2 - Word_Pause[2]->Rect->getGlobalBounds().width / 2, Y + 3 * (Height / 6) - Word_Pause[2]->Rect->getGlobalBounds().height);
	//Word_Pause[3]->Move(X + Length / 2 - Word_Pause[3]->Rect->getGlobalBounds().width / 2, Y + 4 * (Height / 6) - Word_Pause[3]->Rect->getGlobalBounds().height);

}