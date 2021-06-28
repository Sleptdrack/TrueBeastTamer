#include "pch.h"
#include "Arena.h"
#include "Fight.h"
#include "Pause.h"
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
	//Crear clase que maneje un cuadro con valores 
	Screen->W->setSize(sf::Vector2u(PathSource::Resolution[0], PathSource::Resolution[1]));//erase after
	B = b;
}

void GameModel::Arena::Draw()
{
	Screen->Draw();
	B->Draw(*Screen->W);
}

void GameModel::Arena::Show(Map^ M){
	M->Player->Bag->open = false;
	M->Player->Move(280, 600);
	M->Player->Bag->Beast[0]->Move(947, 640);
	M->Player->Bag->Beast[0]->Power[0]->Shot->Clear();
	M->Player->Bag->Beast[0]->Power[0]->InUse = false;
	B->Move(947, 157);
	Time t,t1,t2;
	Clock clk,clk1,clk2;

	//julio
	bool pause = false;

	while (Screen->W->isOpen()) {
		sf::Event event;
		while (Screen->W->pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				pause = true;
				M->Player->PauseObj->OpenPause(pause);
			}
		}

		if (!pause)
		{
			t = clk.getElapsedTime();
			t1 = clk1.getElapsedTime();
			t2 = clk2.getElapsedTime();
			clk.restart();
			sf::Event event;
			while (Screen->W->pollEvent(event)) {
				if (Screen->Word[0]->Click(*Screen->W)) {
					Screen->W->close();
					B->Health[3] = 0;
				}
			}
			Movement::Move(M->Player->Bag->Beast[0], t, Tspace);
			Behavior::UpdateBehavior(B);
			Behavior::Move(B, t, Tspace);
			if (t2.asMilliseconds() > 200) {
				M->Player->Bag->Beast[0]->Update();
				clk2.restart();
			}
			Interraction::UsePower(M->Player->Bag->Beast[0], *Screen->W);
			if (t1.asMilliseconds() > 100) {
				Movement::ShotDinamics(M->Player->Bag->Beast[0]->Power[0]);
				clk1.restart();
			}
			Fight::Battle(B, M->Player);
			if (B->Health[3] <= 0) {
				M->Player->Bag->Beast[0]->Exp += 10;
				M->Player->Bag->AddBeast(B);
				Screen->W->close();
			}//reemplazar por metodo para atrapar o liberar Beast
			Screen->W->clear();
			Draw();
			M->Player->Draw(*Screen->W);
			/*for (int i = 0; i < M->Player->Bag->Beast->Count; i++) {
				M->Player->Bag->Beast[i]->Draw(*Screen->W);
			}*/
			M->Player->Bag->Beast[0]->Draw(*Screen->W);
			if (M->Player->Bag->Beast[0]->Power[0]->InUse) {
				M->Player->Bag->Beast[0]->Power[0]->Shot[0]->Draw(*Screen->W);
			}
			
		}
		M->Player->PauseObj->SelectOption(*Screen->W, pause);
		M->Player->PauseObj->DrawPause(*Screen->W);
		Screen->W->display();
	}
	
}
