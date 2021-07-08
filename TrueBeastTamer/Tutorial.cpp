#include "pch.h"
#include "Tutorial.h"

GameView::Tutorial::Tutorial(Tamer^ t)
{
	T = t;
	Screen = gcnew GameView::Screen(0, 0, 1920, 1080, (sf::String)"Tutorial");
	//Presentacion Beast
	Beast = gcnew List<GameModel::Beast^>();
	for (int i = 0; i < 6; i++) {
		GameModel::Beast^ b1 = gcnew GameModel::Beast(static_cast<BeastName>(i));
		Beast->Add(b1);
		GameView::Word^ w = gcnew GameView::Word(0, 0, Beast[i]->TagName, 24, sf::Color::Red);
		Screen->Word->Add(w);
		Beast[i]->Move((i + 1) * (Screen->Length / (6 + 1)) - Beast[i]->Length / 2, 200);
		Screen->Word[i+1]->Move(Beast[i]->X-Screen->Word[i+1]->Rect->getGlobalBounds().width/2+Beast[i]->Length/2, Beast[i]->Y + Beast[i]->Height);	
		
	}
	//Presentacion Word
	GameView::Word^ w = gcnew GameView::Word(0, 0, "Choose your Beast", 48, sf::Color::Red);
	Screen->Word->Add(w);
	
	Screen->Word[Screen->Word->Count-1]->Move(Screen->Length / 2 - Screen->Word[5]->Rect->getGlobalBounds().width / 2, 100);
	Screen->W->setSize(sf::Vector2u(PathSource::Resolution[0], PathSource::Resolution[1]));//erase after

	GameView::Word^ manual1 = gcnew GameView::Word(30, 400, "Movement:", 24, sf::Color::Red);
	Screen->Word->Add(manual1);

    GameView::Word^ manual2 = gcnew GameView::Word(30, 570, "Press W key to move upwards ", 24, sf::Color::Red);
	Screen->Word->Add(manual2);

	GameView::Word^ manual3 = gcnew GameView::Word(30, 620, "Press S key to move downwards ", 24, sf::Color::Red);
	Screen->Word->Add(manual3);

	GameView::Word^ manual4 = gcnew GameView::Word(30, 670, "Press A key to move to the right ", 24, sf::Color::Red);
	Screen->Word->Add(manual4);

	GameView::Word^ manual5 = gcnew GameView::Word(30, 720, "Press D key to move to the left ", 24, sf::Color::Red);
	Screen->Word->Add(manual5);

	GameView::Word^ manual6 = gcnew GameView::Word(30, 790, "Kills: ", 24, sf::Color::Red);
	Screen->Word->Add(manual6);

	GameView::Word^ manual7 = gcnew GameView::Word(30, 850, "Press right mouse click to attack ", 24, sf::Color::Red);
	Screen->Word->Add(manual7);
	

}

void GameView::Tutorial::DrawTutorial()
{
	
	sf::Texture texTuto1;
	texTuto1.loadFromFile("../Imagenes/up.png");
	sf::Sprite spri1(texTuto1);
	spri1.setPosition(500, 570);
	spri1.scale(sf::Vector2f(0.20, 0.20));
	Screen->W->draw(spri1);

	sf::Texture texTuto2;
	texTuto2.loadFromFile("../Imagenes/down.png");
	sf::Sprite spri2(texTuto2);
	spri2.setPosition(500, 620);
	spri2.scale(sf::Vector2f(0.20, 0.20));
	Screen->W->draw(spri2);

	sf::Texture texTuto3;
	texTuto3.loadFromFile("../Imagenes/rigth.png");
	sf::Sprite spri3(texTuto3);
	spri3.setPosition(500, 670);
	spri3.scale(sf::Vector2f(0.20, 0.20));
	Screen->W->draw(spri3);

	sf::Texture texTuto4;
	texTuto4.loadFromFile("../Imagenes/left.png");
	sf::Sprite spri4(texTuto4);
	spri4.setPosition(500, 720);
	spri4.scale(sf::Vector2f(0.20, 0.20));
	Screen->W->draw(spri4);

	sf::Texture texTuto5;
	texTuto5.loadFromFile("../Imagenes/Teclado.jpg");
	sf::Sprite spri5(texTuto5);
	spri5.setPosition(100, 450);
	spri5.scale(sf::Vector2f(0.2,0.2));
	Screen->W->draw(spri5);

	for (int s = 520; s <= 700;s++) {
		
		sf::Texture texTuto6;
		texTuto6.loadFromFile("../Imagenes/BaseAttack.png");
		sf::Sprite spri6(texTuto6);
		spri6.setPosition(s, 850);
		spri6.scale(sf::Vector2f(1.7, 1.7));
		Screen->W->draw(spri6);
		
	}
}


void GameView::Tutorial::Draw()
{
	
	Screen->Draw(); 
	DrawTutorial();
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
		for (int i = 1; i <= 6; i++) {
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
