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
