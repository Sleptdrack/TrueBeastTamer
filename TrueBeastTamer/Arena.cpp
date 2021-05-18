#include "pch.h"
#include "Arena.h"

GameModel::Arena::Arena(Beast^ b)
{
	Texture = new sf::Texture();
	//Sprite = new sf::Sprite();
	Screen = gcnew GameView::Screen(0,0,1920,1080,"Arena");
	Texture->loadFromFile("../Imagenes/Arena.jpg");
	Screen->Rect->setTexture(Texture);
	Screen->Rect->setFillColor(sf::Color::White);
	B = b;
}

void GameModel::Arena::Draw()
{
	Screen->Draw(*Screen->W);
	B->Draw(*Screen->W);
}

void GameModel::Arena::Show(Map^ M){
	M->Player->Move(880, 768);
	B->Move(947, 157);
	Time t;
	Clock clk;
	while (Screen->W->isOpen()) {
		t = clk.getElapsedTime();
		clk.restart();
		sf::Event event;
		while (Screen->W->pollEvent(event)){
			if (Screen->Word[0]->Click(*Screen->W)) {
				Screen->W->close();
				B->Health[3] = 0;
			}
		}
		Movement::Move(M->Player, t);
		Screen->W->clear();
		Draw();
		M->Player->Draw(*Screen->W);
		Screen->W->display();
	}
	
}
