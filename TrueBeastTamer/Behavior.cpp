#include "pch.h"
#include "Behavior.h"



void GameModel::Behavior::Load()
{
	Destiny = gcnew Coords(1000,600);
}

void GameModel::Behavior::Move(Beast^ G, Time t, RectangleShape* R,Beast^ B)
{
	if (!Loaded) {
		Load();
		Loaded = true;
	}
	if (G->State == Calm && DestinationReached) {
		Destiny->x = R->getPosition().x+rand() % (int)(R->getGlobalBounds().width - G->Length);
		Destiny->y = R->getPosition().y+rand() % (int)(R->getGlobalBounds().height - G->Height);
		DestinationReached = false;
	}
	if ((G->State == Annoyed || G->State == Angry || G->State == Mad|| G->State == Furious)&& DestinationReached) {
		Destiny->x = B->X- 2*B->Length + rand() % (int)(4*B->Length);
		Destiny->y = B->Y- 2 * B->Height + rand() % (int)(4*B->Height);
		DestinationReached = false;
	}
	if (!DestinationReached) {
		if (Destiny->x > G->X) {
			if (G->X + G->Speed * G->Length * t.asSeconds() < Destiny->x) {
				G->X += G->Speed * G->Length * t.asSeconds();
			}
			else {
				G->X = Destiny->x;
			}
			G->CurrentAnimation = AnimationIndex::WalkingRight;
		}
		if (Destiny->x < G->X) {
			if (G->X - G->Speed * G->Length * t.asSeconds() > Destiny->x) {
				G->X -= G->Speed * G->Length * t.asSeconds();
			}
			else {
				G->X = Destiny->x;
			}
			G->CurrentAnimation = AnimationIndex::WalkingLeft;
		}
		if (Destiny->y < G->Y) {
			if (G->Y - G->Speed * G->Height * t.asSeconds() > Destiny->y) {
				G->Y -= G->Speed * G->Height * t.asSeconds();
			}
			else {
				G->Y = Destiny->y;
			}
			G->CurrentAnimation = AnimationIndex::WalkingUp;
		}
		if (Destiny->y > G->Y) {
			if (G->Y + G->Speed * G->Height * t.asSeconds() < Destiny->y) {
				G->Y += G->Speed * G->Height * t.asSeconds();
			}
			else {
				G->Y = Destiny->y;
			}
			G->CurrentAnimation = AnimationIndex::WalkingDown;
		}
		if (Destiny->x == G->X && Destiny->y == G->Y) {
			DestinationReached = true;
		}
		G->Move(G->X, G->Y);
	}
}

void GameModel::Behavior::Attack(Beast^ G, RectangleShape* R,Beast^ B){
	if (G->State == Annoyed) {
		if (G->Power[0]->InUse == false) {
			G->Power[0]->InUse = true;
			sf::Vector2f dt;
			dt.x = float((rand() % (int)(R->getSize().x * 100)) / 100) + R->getPosition().x;
			dt.y = float((rand() % (int)(R->getSize().y * 100)) / 100 + R->getPosition().y);
			GameModel::Shot^ s = gcnew GameModel::Shot(dt, sf::Vector2f(G->X + G->Length / 2, G->Y + G->Height / 2));
			G->Power[0]->Shot->Add(s);
		}
	}
	else if (G->State == Angry) {
		if (G->Power[0]->InUse == false) {
			G->Power[0]->InUse = true;
			sf::Vector2f dt;
			dt.x = B->X-200+rand()%400;
			dt.y = B->Y - 200 + rand() % 400;
			GameModel::Shot^ s = gcnew GameModel::Shot(dt, sf::Vector2f(G->X + G->Length / 2, G->Y + G->Height / 2));
			G->Power[0]->Shot->Add(s);
		}
	}
	else if (G->State == Mad) {
		if (G->Power[0]->InUse == false) {
			G->Power[0]->InUse = true;
			sf::Vector2f dt;
			dt.x = B->X - 100 + rand() % 200;
			dt.y = B->Y - 100 + rand() % 200;
			GameModel::Shot^ s = gcnew GameModel::Shot(dt, sf::Vector2f(G->X + G->Length / 2, G->Y + G->Height / 2));
			G->Power[0]->Shot->Add(s);
		}
	}
	else if (G->State == Furious) {
		if (G->Power[0]->InUse == false) {
			G->Power[0]->InUse = true;
			sf::Vector2f dt;
			dt.x = B->X;
			dt.y = B->Y;
			GameModel::Shot^ s = gcnew GameModel::Shot(dt, sf::Vector2f(G->X + G->Length / 2, G->Y + G->Height / 2));
			G->Power[0]->Shot->Add(s);
		}
	}
}

void GameModel::Behavior::UpdateBehavior(Beast^ G)
{
	if (G->Health[3] >= G->Health[2] * .75) {
		G->State = Calm;
	}
	else if (G->Health[3] >= G->Health[2] * .50) {
		G->State = Annoyed;
	}
	else if (G->Health[3] >= G->Health[2] * .25) {
		G->State = Angry;
	}
	else if (G->Health[3] >= G->Health[2] * .10) {
		G->State = Mad;
	}
	else {
		G->State = Furious;
	}
}

GameModel::Coords::Coords(float xx, float yy)
{
	x = xx;
	y = yy;
}
