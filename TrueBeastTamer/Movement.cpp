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
