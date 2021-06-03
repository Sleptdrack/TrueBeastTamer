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

void GameController::Movement::ShotDinamics(Power^ p)
{
	if (p->InUse) {
		float x = p->Shot[0]->end->x - p->Shot[0]->start->x;
		float y = p->Shot[0]->end->y - p->Shot[0]->start->y;
		float m = y / x;
		float plus = p->Range / (10 * pow((1 + pow(m, 2)), 0.5));
		if (p->Shot[0]->destiny>=10) {
			p->InUse = false;
			p->Shot->RemoveAt(0);
		}
		else {
			if(x>0)p->Shot[0]->Move(p->Shot[0]->X + plus, p->Shot[0]->Y + plus * m);
			else p->Shot[0]->Move(p->Shot[0]->X - plus, p->Shot[0]->Y - plus * m);
			p->Shot[0]->destiny += 1;
		}
	}
}
