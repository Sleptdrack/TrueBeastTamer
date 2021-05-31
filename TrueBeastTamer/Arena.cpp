#include "pch.h"
#include "Arena.h"

GameModel::Arena::Arena(Beast^ b)
{
	Texture = new sf::Texture();
	//Sprite = new sf::Sprite();
	Screen = gcnew GameView::Screen(0,0,1920,1080,"Arena");//size 1920x1080
	Texture->loadFromFile("../Imagenes/Arena.jpg");
	Screen->Rect->setTexture(Texture);
	Screen->Rect->setFillColor(sf::Color::White);
	Tspace = new RectangleShape(sf::Vector2f(850, 480));
	Tspace->setPosition(505, 212);
	B = b;
}

void GameModel::Arena::Draw()
{
	Screen->Draw();
	B->Draw(*Screen->W);
}

void GameModel::Arena::Show(Map^ M){
	M->Player->Move(280, 600);
	M->Player->Bag->Beast[0]->Move(947, 640);
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
		Movement::Move(M->Player->Bag->Beast[0], t,Tspace);
		//std::cout << PathSource::SystoStd(M->Player->X.ToString()) + (std::string)" " + PathSource::SystoStd(M->Player->Y.ToString()) + "\n";
		Screen->W->clear();
		Draw();
		M->Player->Draw(*Screen->W);
		for (int i = 0; i < M->Player->Bag->Beast->Count; i++) {
			M->Player->Bag->Beast[i]->Draw(*Screen->W);
		}
		Screen->W->display();
	}
	
}
