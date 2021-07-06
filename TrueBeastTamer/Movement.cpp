#include "pch.h"
#include "Movement.h"

void GameController::Movement::Move(GameObject^ G, Time t) {
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		G->Y -= G->Speed * G->Height * t.asSeconds();
		G->CurrentAnimation = AnimationIndex::WalkingUp;
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		G->Y += G->Speed * G->Height * t.asSeconds();
		G->CurrentAnimation = AnimationIndex::WalkingDown;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		G->X += G->Speed * G->Length * t.asSeconds();
		G->CurrentAnimation = AnimationIndex::WalkingRight;
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		G->X -= G->Speed * G->Length * t.asSeconds();
		G->CurrentAnimation = AnimationIndex::WalkingLeft;
	}
	//Idle animations
	if (!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S) && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A)) {
		//if(G->CurrentAnimation = WalkingUp){
		//G->CurrentAnimation = AnimationIndex::StopUp;}
		G->CurrentAnimation = AnimationIndex::Idle;
	}
	G->Move(G->X, G->Y);
}

void GameController::Movement::Move(GameObject^ G, Time t, RectangleShape* R)
{
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		if (R->getGlobalBounds().contains(G->X, G->Y - G->Speed * G->Height * t.asSeconds())) {
			G->Y -= G->Speed * G->Height * t.asSeconds();
		}
		//insertar currentanimation
		G->CurrentAnimation = AnimationIndex::WalkingUp;
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		if (R->getGlobalBounds().contains(G->X, G->Y + G->Speed * G->Height * t.asSeconds())) {
			G->Y += G->Speed * G->Height * t.asSeconds();
		}
		G->CurrentAnimation = AnimationIndex::WalkingDown;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (R->getGlobalBounds().contains(G->X + G->Speed * G->Length * t.asSeconds(), G->Y)) {
			G->X += G->Speed * G->Length * t.asSeconds();
		}
		G->CurrentAnimation = AnimationIndex::WalkingRight;
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		if (R->getGlobalBounds().contains(G->X - G->Speed * G->Length * t.asSeconds(), G->Y)) {
			G->X -= G->Speed * G->Length * t.asSeconds();
		}
		G->CurrentAnimation = AnimationIndex::WalkingLeft;
	}
	//Insert Idle Animation
	G->Move(G->X, G->Y);
}

void GameController::Movement::ShotDinamics(Beast^ p)
{
	if (p->Power[0]->InUse && p->Power[0]->Shot->Count > 0) {
		*p->Power[0]->time = p->Power[0]->clk->getElapsedTime();
		float x = p->Power[0]->Shot[0]->end->x - p->Power[0]->Shot[0]->start->x;
		float y = p->Power[0]->Shot[0]->end->y - p->Power[0]->Shot[0]->start->y;
		float m = y / x;
		float plus = p->Power[0]->Range / (p->Power[0]->cooldown * (1- p->Cooldown[3]*.01) * pow((1 + pow(m, 2)), 0.5));
		if (p->Power[0]->time->asMilliseconds()> p->Power[0]->cooldown*(1 - p->Cooldown[3] * .01)) {
			p->Power[0]->clk->restart();
			p->Power[0]->InUse = false;
			p->Power[0]->Shot->RemoveAt(0);
			p->Power[0]->Move->stop();
			p->Power[0]->Hit->play();
		}
		else {
			p->Power[0]->Move->play();
			p->Power[0]->Move->setLoop(true);
			if(x>0)p->Power[0]->Shot[0]->Move(p->Power[0]->Shot[0]->X + plus, p->Power[0]->Shot[0]->Y + plus * m);
			else p->Power[0]->Shot[0]->Move(p->Power[0]->Shot[0]->X - plus, p->Power[0]->Shot[0]->Y - plus * m);
		}
	}
}
