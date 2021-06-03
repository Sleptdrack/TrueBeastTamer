#include "pch.h"
#include "Interraction.h"

void GameController::Interraction::SetStateBag(Tamer^ T, RenderWindow& rt)
{
	if (T->Bag->open) {
		if (T->Bag->State == Window_Bag::Menu) {
			if (T->Bag->Word[2]->Click(rt)) {
				T->Bag->State = Window_Bag::Beasts;
			}
			if (T->Bag->Word[1]->Click(rt)) {
				T->Bag->State = Window_Bag::Items;
			}
			if (T->Bag->Word[3]->Click(rt)) {
				T->Bag->State = Window_Bag::Setting;
			}
			if (T->Bag->Word[4]->Click(rt)) {
				try {
					GameManager::UpdatePlayer(T);
				}
				catch (...) {
					rt.close();
				}
				
			}
			if (T->Bag->Word[5]->Click(rt)) {
				rt.close();
				GameManager::UpdatePlayer(T);
			}
		}
		if (T->Bag->State == Window_Bag::Beasts) {
			if (T->Bag->Word_Beast[1]->Click(rt)) {
				T->Bag->State = Window_Bag::Menu;
			}
		}
		if (T->Bag->State == Items) {
			if (T->Bag->Word_Item[1]->Click(rt)) {
				T->Bag->State = Window_Bag::Menu;
			}
		}
		if (T->Bag->State == Setting) {
			if (T->Bag->Word_Setting[1]->Click(rt)) {
				T->Bag->State = Window_Bag::Menu;
			}
		}
	}
	else {
		T->Bag->State = Window_Bag::Menu;
	}
}

void GameController::Interraction::UsePower(Beast^ b, RenderWindow& rt)
{
	if (b->Power[0]->InUse == false) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) ){
			b->Power[0]->InUse = true;
			sf::Vector2f mouse =(sf::Vector2f)rt.mapPixelToCoords(sf::Mouse::getPosition(rt));
			GameModel::Shot^ s = gcnew GameModel::Shot(mouse, sf::Vector2f(b->X+b->Length/2, b->Y+b->Height/2));
			b->Power[0]->Shot->Add(s);
		}
	}
}
