#include "pch.h"
#include "Movement.h"

void GameController::Movement::Move(GameObject^ G, Time t){
	if (Keyboard::isKeyPressed(Keyboard::W)) {
			G->Y -= G->Speed * G->Height * t.asSeconds();
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
			G->Y += G->Speed * G->Height * t.asSeconds();
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
			G->X += G->Speed * G->Length * t.asSeconds();
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
			G->X -= G->Speed * G->Length * t.asSeconds();
	}
	G->Move(G->X, G->Y);
}

void GameController::Movement::Move(GameObject^ G, Time t, RectangleShape* R)
{
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		if (R->getGlobalBounds().contains(G->X, G->Y - G->Speed * G->Height * t.asSeconds())) {
			G->Y -= G->Speed * G->Height * t.asSeconds();
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		if (R->getGlobalBounds().contains(G->X, G->Y + G->Speed * G->Height * t.asSeconds())) {
			G->Y += G->Speed * G->Height * t.asSeconds();
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (R->getGlobalBounds().contains(G->X + G->Speed * G->Length * t.asSeconds(), G->Y)) {
			G->X += G->Speed * G->Length * t.asSeconds();
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		if (R->getGlobalBounds().contains(G->X - G->Speed * G->Length * t.asSeconds(), G->Y )) {
			G->X -= G->Speed * G->Length * t.asSeconds();
		}
	}
	G->Move(G->X, G->Y);
}

void GameController::Movement::MoveAttack(GameObject^ G, Time t)
{
	sf::Vector2i globalPosition = sf::Mouse::getPosition(); // posicion del mouse
	//int xp = 30;
	//int yp = 30;

	//int n =  abs(globalPosition.x - xp)/50;
	//int x_r = xp;
	//int y_r;
	//for(int i=0;i<n;i++)
	//{
	//	y_r = (yp - globalPosition.y) * (x_r - xp) / (xp - globalPosition.x);
	//	x_r = x_r + n;
	//	G->X = x_r;
	//	G->Y = y_r;
	//	G->Move(G->X, G->Y);
	//}

	G->X = globalPosition.x;
	G->Y = globalPosition.y;
	G->Move(G->X, G->Y);
}

void GameController::Movement::ShotDinamics(Power^ p)
{
	if (p->InUse) {
		if (p->Shot[0]->destiny>=10) {
			p->InUse = false;
			p->Shot->RemoveAt(0);
		}
		else {
			p->Shot[0]->Move(p->Shot[0]->X + (p->Shot[0]->end->x - p->Shot[0]->start->x) / 10, p->Shot[0]->Y + (p->Shot[0]->end->y - p->Shot[0]->start->y) / 10);
			p->Shot[0]->destiny += 1;
		}
	}
}
