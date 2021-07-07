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
	//erase later
	Tspace->setOutlineThickness(1);
	Tspace->setOutlineColor(sf::Color::Red);

	//Crear clase que maneje un cuadro con valores 
	Screen->W->setSize(sf::Vector2u(PathSource::Resolution[0], PathSource::Resolution[1]));//erase after
	B = b;
	

}

void GameModel::Arena::Draw()
{
	Screen->Draw();
	B->Draw(*Screen->W);
	//
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
	int Chosen = 0;
	//julio
	bool pause = false;

	bool pWin = false, pWin2 = false, pLost = false;
	int get;
	GameView::MessageHUB^ BeastTaken = gcnew GameView::MessageHUB("Usted a atrapado a "+B->TagName);
	GameView::MessageHUB^ BeastEscape = gcnew GameView::MessageHUB("La Bestia se a escapado");
	GameView::MessageHUB^ PlayerDefeated = gcnew GameView::MessageHUB("Usted a sido derrotado");
	//
	GameView::BeastHUB^ B1 = gcnew GameView::BeastHUB(1300, 0, B);
	//
	GameView::BeastHUB^ B2 = gcnew GameView::BeastHUB(100, 0, M->Player->Bag->Beast[Chosen]);

	while (Screen->W->isOpen()) {
		sf::Event event;
		while (Screen->W->pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				pause = true;
				M->Player->PauseObj->OpenPause(pause);
			}
		}

		if (!pause && !pWin && !pWin2 && !pLost){
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
			Movement::Move(M->Player->Bag->Beast[Chosen], t, Tspace);
			Behavior::UpdateBehavior(B);
			Behavior::Move(B, t, Tspace,M->Player->Bag->Beast[Chosen]);
			if (t2.asMilliseconds() > 200) {
				M->Player->Bag->Beast[Chosen]->Update();
				clk2.restart();
			}
			Interraction::UsePower(M->Player->Bag->Beast[Chosen], *Screen->W);
			Behavior::Attack(B, Tspace, M->Player->Bag->Beast[Chosen]);
			//verificar funcionamiento
			Movement::ShotDinamics(M->Player->Bag->Beast[Chosen]);
			Movement::ShotDinamics(B);
			//
			Interraction::ChangeBeast(M->Player, &Chosen);
			Fight::Battle(B, M->Player,&Chosen);
			//
			B->LevelUp();
			for (int i = 0; i < M->Player->Bag->Beast->Count; i++) {
				M->Player->Bag->Beast[i]->LevelUp();
			}
			//
			if (B->Health[3] <= 0) {
				get = rand() % 100;
				B->Power[0]->Stop();
				for (int i = 0; i < M->Player->Bag->Beast->Count; i++) {
					M->Player->Bag->Beast[i]->Power[0]->Stop();
				}
				if (get >= 50) {
					M->Player->Bag->AddBeast(B);
					pWin = true;
				}
				else {
					pWin2 = true;
				}
			}//reemplazar por metodo para atrapar o liberar Beast
			B1->Update(B);
			B2->Update(M->Player->Bag->Beast[Chosen]);
		}

		Screen->W->clear();
		Draw();
		M->Player->Draw(*Screen->W);
		/*for (int i = 0; i < M->Player->Bag->Beast->Count; i++) {
			M->Player->Bag->Beast[i]->Draw(*Screen->W);
		}*/
		M->Player->Bag->Beast[Chosen]->Draw(*Screen->W);
		if (M->Player->Bag->Beast[Chosen]->Power[0]->InUse && M->Player->Bag->Beast[Chosen]->Power[0]->Shot->Count > 0) {
			M->Player->Bag->Beast[Chosen]->Power[0]->Shot[0]->Draw(*Screen->W);
		}
		if (B->Power[0]->InUse && B->Power[0]->Shot->Count > 0) {
			B->Power[0]->Shot[0]->Draw(*Screen->W);
		}
		M->Player->PauseObj->SelectOption(*Screen->W, pause);
		M->Player->PauseObj->DrawPause(*Screen->W);
		B1->Draw(*Screen->W);
		B2->Draw(*Screen->W);
		if(pWin) {
			BeastTaken->Stay(&pWin, *Screen->W);
			if (!pWin)Screen->W->close();
			BeastTaken->Draw(*Screen->W);
		}
		if (pWin2) {
			BeastEscape->Stay(&pWin2, *Screen->W);
			if (!pWin2)Screen->W->close();
			BeastEscape->Draw(*Screen->W);
		}
		Screen->W->display();
	}
	
}
