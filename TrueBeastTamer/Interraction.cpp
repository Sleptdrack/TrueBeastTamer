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
			for (int i = 0; i < T->Bag->Beast->Count; i++) {
				if (T->Bag->Word_Beast[3*(i+1)]->Click(rt)) {
					T->Bag->setEditMode(i);
					T->Bag->State = Edit;
				}
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
		if (T->Bag->State == Edit) {
			if (T->Bag->Word_Edit[1]->Click(rt)) {
				T->Bag->Word_Edit[2]->on = false;
				T->Bag->State = Window_Bag::Beasts;
			}
		}
	}
	else {
		T->Bag->State = Window_Bag::Menu;
	}
}

void GameController::Interraction::MoveBag(Tamer^ T, RenderWindow& rt, sf::Vector2f* t)
{
	if (T->Bag->open) {
		if (!T->Bag->moving) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				T->Bag->moving = true;
				*t= (sf::Vector2f)rt.mapPixelToCoords(sf::Mouse::getPosition(rt));
			}
		}
		else {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				sf::Vector2f mouse = (sf::Vector2f)rt.mapPixelToCoords(sf::Mouse::getPosition(rt));
				T->Bag->Move(T->Bag->X+mouse.x - t->x,T->Bag->Y+mouse.y - t->y);
				*t = (sf::Vector2f)rt.mapPixelToCoords(sf::Mouse::getPosition(rt));
			}
			else {
				T->Bag->moving = false;
			}
		}
	}
}
void GameController::Interraction::MovePause(Tamer^ T, RenderWindow& rt, sf::Vector2f* t)
{
	if (T->PauseObj->m_flagPause) {
		if (!T->PauseObj->moving) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				T->PauseObj->moving = true;
				*t = (sf::Vector2f)rt.mapPixelToCoords(sf::Mouse::getPosition(rt));
			}
		}
		else {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				sf::Vector2f mouse = (sf::Vector2f)rt.mapPixelToCoords(sf::Mouse::getPosition(rt));
				T->PauseObj->Move(T->PauseObj->X + mouse.x - t->x, T->PauseObj->Y + mouse.y - t->y);
				*t = (sf::Vector2f)rt.mapPixelToCoords(sf::Mouse::getPosition(rt));
			}
			else {
				T->PauseObj->moving = false;
			}
		}
	}
}
void GameController::Interraction::MoveHealth(Tamer^ T, RenderWindow& rt, sf::Vector2f* t)
{
	if (T->HealthObj->m_flagHealth) {
		if (!T->HealthObj->moving) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				T->HealthObj->moving = true;
				*t = (sf::Vector2f)rt.mapPixelToCoords(sf::Mouse::getPosition(rt));
			}
		}
		else {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				sf::Vector2f mouse = (sf::Vector2f)rt.mapPixelToCoords(sf::Mouse::getPosition(rt));
				T->HealthObj->Move(T->HealthObj->X + mouse.x - t->x, T->HealthObj->Y + mouse.y - t->y);
				*t = (sf::Vector2f)rt.mapPixelToCoords(sf::Mouse::getPosition(rt));
			}
			else {
				T->HealthObj->moving = false;
			}
		}
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

void GameController::Interraction::RenameBeast(Tamer^ T, RenderWindow& rt, Event e)
{
	sf::String* n = new sf::String(PathSource::SystoStd(T->Bag->Word_Edit[2]->T));
	if (T->Bag->State == Edit) {
		if (T->Bag->Word_Edit[2]->Click(rt)) {
			while (sf::Mouse::isButtonPressed(Mouse::Button::Left));
			std::cout << T->Bag->Word_Edit[2]->on;
			if (T->Bag->Word_Edit[2]->on) {
				T->Bag->Word_Edit[2]->on = false;
			}
			else {
				T->Bag->Word_Edit[2]->on = true;
			}
		}
		if (T->Bag->Word_Edit[2]->on) {
			T->Bag->Word_Edit[2]->Fill(e, n);
			T->Bag->Beast[System::Int16::Parse(T->Bag->Word_Edit[0]->T)]->TagName = T->Bag->Word_Edit[2]->T;
		}
	}
}
