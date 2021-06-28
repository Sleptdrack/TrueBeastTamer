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
	if (G->State == Annoyed && DestinationReached) {
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
