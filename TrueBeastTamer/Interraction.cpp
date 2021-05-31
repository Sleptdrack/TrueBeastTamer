#include "pch.h"
#include "Interraction.h"

void GameController::Interraction::SetStateBag(Tamer^ T, RenderWindow& rt)
{
	if (T->Bag->open) {
		if (T->Bag->State == Window_Bag::Menu) {
			if (T->Bag->Word[2]->Click(rt)) {
				T->Bag->State = Window_Bag::Beasts;
			}
		}
	}
	else {
		T->Bag->State = Window_Bag::Menu;
	}
}
