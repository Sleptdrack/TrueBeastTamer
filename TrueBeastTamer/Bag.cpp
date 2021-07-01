#include "pch.h"
#include "Bag.h"
#include<string>
GameModel::Bag::Bag()
{
	Length = 500;
	Height = 500;
	X = 0;
	Y = 0;
	FrameSize = 774;
	changing = false;
	Word = gcnew List<GameView::Word^>();
	//State Menu
	GameView::Word^ w1 = gcnew GameView::Word(0, 0, "Bag", 24, sf::Color(255,101,80,255));
	w1->Move(X + Length / 2 - w1->Rect->getGlobalBounds().width/2, Y + 1 * (Height / 6) - w1->Rect->getGlobalBounds().height);
	GameView::Word^ w2 = gcnew GameView::Word(0, 0, "Items", 24, sf::Color(255, 101, 80, 255));
	w2->Move(X + 1*(Length /4) - w2->Rect->getGlobalBounds().width/2, Y + 2 * (Height / 6) - w2->Rect->getGlobalBounds().height);
	GameView::Word^ w3 = gcnew GameView::Word(0, 0, "Beasts", 24, sf::Color(255, 101, 80, 255));
	w3->Move(X +3* (Length / 4) - w3->Rect->getGlobalBounds().width/2, Y + 2 * (Height / 6) - w3->Rect->getGlobalBounds().height);
	GameView::Word^ w4 = gcnew GameView::Word(0,0, "Settings", 24, sf::Color(255, 101, 80, 255));
	w4->Move(X + Length / 2 - w4->Rect->getGlobalBounds().width/2, Y + 3 * (Height / 6) - w4->Rect->getGlobalBounds().height);
	GameView::Word^ w5 = gcnew GameView::Word(0, 0, "Save", 24, sf::Color(255, 101, 80, 255));
	w5->Move(X + Length / 2 - w5->Rect->getGlobalBounds().width/2, Y + 4 * (Height / 6) - w5->Rect->getGlobalBounds().height);
	GameView::Word^ w6 = gcnew GameView::Word(0, 0, "Log Out", 24, sf::Color(255, 101, 80, 255));
	w6->Move(X + Length / 2 - w6->Rect->getGlobalBounds().width/2, Y + 5 * (Height / 6) - w6->Rect->getGlobalBounds().height);
	Word->Add(w1);
	Word->Add(w2);
	Word->Add(w3);
	Word->Add(w4);
	Word->Add(w5);
	Word->Add(w6);

	//State Beasts
	Beast = gcnew List<GameModel::Beast^>();
	Word_Beast = gcnew List<GameView::Word^>();
	GameView::Word^ B1 = gcnew GameView::Word(0, 0, "Beasts", 24, sf::Color(255, 101, 80, 255));
	B1->Move(X + Length / 2 - B1->Rect->getGlobalBounds().width / 2, Y + 1 * (Height / 6) - B1->Rect->getGlobalBounds().height);
	GameView::Word^ B2 = gcnew GameView::Word(X+20, Y + 1 * (Height / 6) - B1->Rect->getGlobalBounds().height, "Back", 24, sf::Color(255, 101, 80, 255));
	Word_Beast->Add(B1);
	Word_Beast->Add(B2);
	//State Items
	Word_Item = gcnew List<GameView::Word^>();
	GameView::Word^I1 = gcnew GameView::Word(0, 0, "Items", 24, sf::Color(255, 101, 80, 255));
	I1->Move(X + Length / 2 - I1->Rect->getGlobalBounds().width / 2, Y + 1 * (Height / 6) - I1->Rect->getGlobalBounds().height);
	GameView::Word^ I2 = gcnew GameView::Word(X + 20, Y + 1 * (Height / 6) - I1->Rect->getGlobalBounds().height, "Back", 24, sf::Color(255, 101, 80, 255));
	Word_Item->Add(I1);
	Word_Item->Add(I2);
	//State Setting
	Word_Setting = gcnew List<GameView::Word^>();
	GameView::Word^ S1 = gcnew GameView::Word(0, 0, "Settings", 24, sf::Color(255, 101, 80, 255));
	S1->Move(X + Length / 2 - S1->Rect->getGlobalBounds().width / 2, Y + 1 * (Height / 6) - S1->Rect->getGlobalBounds().height);
	GameView::Word^ S2 = gcnew GameView::Word(X + 20, Y + 1 * (Height / 6) - S1->Rect->getGlobalBounds().height, "Back", 24, sf::Color(255, 101, 80, 255));
	Word_Setting->Add(S1);
	Word_Setting->Add(S2);
	//State Edit
	Stat = nullptr;
	Word_Edit = gcnew List<GameView::Word^>();

	Word_Edit->Add(gcnew GameView::Word(0, 0, "", 24, sf::Color::Black));

	Word_Edit->Add(gcnew GameView::Word(X+20,Y+(1)*Height/13, "Back", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(0, 0, "", 24, sf::Color::Black));
	Word_Edit[2]->Move(X + Length / 2, Y + (1) * Height /13);

	Word_Edit->Add(gcnew GameView::Word(X + 50 + 40, Y + (2) * Height /13, "Health: ", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 50 + 40 +Word_Edit[3]->Rect->getGlobalBounds().width, Y + (2) * Height / 13, "", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 50 + 40, Y + (3) * Height / 13, "Level: ", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 50 + 40 + Word_Edit[5]->Rect->getGlobalBounds().width, Y + (3) * Height / 13, "", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 50 + 40, Y + (4) * Height / 13, "Exp: ", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 50 + 40 + Word_Edit[7]->Rect->getGlobalBounds().width, Y + (4) * Height / 13, ""+ "/100", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 20, Y + (5) * Height / 13, "Element: ", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 20 + Word_Edit[9]->Rect->getGlobalBounds().width, Y + (5) * Height / 13, "", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 20, Y + (6) * Height / 13, "Attack: ", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 20 + Word_Edit[11]->Rect->getGlobalBounds().width, Y + (6) * Height / 13, "", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 20, Y + (7) * Height / 13, "Defense: ", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 20 + Word_Edit[13]->Rect->getGlobalBounds().width, Y + (7) * Height / 13, "", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 20, Y + (8) * Height / 13, "Cooldown: ", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 20 + Word_Edit[15]->Rect->getGlobalBounds().width, Y + (8) * Height / 13, ""+ "%", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 20, Y + (9) * Height / 13, "Beast: ", 24, sf::Color::Black));
	Word_Edit->Add(gcnew GameView::Word(X + 20 + Word_Edit[17]->Rect->getGlobalBounds().width, Y + (9) * Height / 13, "", 24, sf::Color::Black));
	setDrawables(PathSource::SystoStd(PathSource::Bag[0]));
	open = false;
	moving = false;
	State = Window_Bag::Menu;
}

void GameModel::Bag::setDrawables(sf::String t){
	GameObject::setDrawables(t);
	Rect = new RectangleShape(sf::Vector2f(Length, Height / 25));
	Rect->setPosition(X, Y);
	Sprite->setColor(sf::Color(111, 29, 116, 255));
	for (int i=0; i < Word->Count; i++) {
		Word[i]->SetParameters(PathSource::SystoStd(PathSource::Word[0]), PathSource::SystoStd(PathSource::Word[1]), Word[i]->Code);
	}
	for (int i = 0; i < Word_Beast->Count; i++) {
		Word_Beast[i]->SetParameters(PathSource::SystoStd(PathSource::Word[0]), PathSource::SystoStd(PathSource::Word[1]), Word_Beast[i]->Code);
	}
	for (int i = 0; i < Word_Item->Count; i++) {
		Word_Item[i]->SetParameters(PathSource::SystoStd(PathSource::Word[0]), PathSource::SystoStd(PathSource::Word[1]), Word_Item[i]->Code);
	}
	for (int i = 0; i < Word_Setting->Count; i++) {
		Word_Setting[i]->SetParameters(PathSource::SystoStd(PathSource::Word[0]), PathSource::SystoStd(PathSource::Word[1]), Word_Setting[i]->Code);
	}
	for (int i = 0; i < Beast->Count; i++) {
		BeastSource::LoadFromFile(PathSource::SystoStd(PathSource::Beast[Beast[i]->Name]));
		Beast[i]->SetDrawables(PathSource::SystoStd(BeastSource::Sprite[0]),
			PathSource::SystoStd(BeastSource::Sound[0]),
			PathSource::SystoStd(BeastSource::Sound[1]));
	}
	for (int i = 0; i < Word_Edit->Count; i++) {
		Word_Edit[i]->SetParameters(PathSource::SystoStd(PathSource::Word[0]), PathSource::SystoStd(PathSource::Word[1]), Word_Edit[i]->Code);
	}
	Stat = nullptr;
}

void GameModel::Bag::setEditMode(int t)
{
	Stat = gcnew GameView::Stat(Beast[t]);
	Stat->Scale(0.5, 0.5);
	Word_Edit[0]->UpdateString(std::to_string(t));
	Word_Edit[2]->UpdateString(PathSource::SystoStd(Beast[t]->TagName));
	Word_Edit[4]->UpdateString(PathSource::SystoStd(Beast[t]->Health[3].ToString() + "/" + Beast[t]->Health[2].ToString()));
	Word_Edit[6]->UpdateString(PathSource::SystoStd(Beast[t]->Level.ToString()));
	Word_Edit[8]->UpdateString(PathSource::SystoStd(Beast[t]->Exp.ToString() + "/100"));
	Word_Edit[10]->UpdateString(ElementString[Beast[t]->Type]);
	Word_Edit[12]->UpdateString(PathSource::SystoStd(Beast[t]->Attack[3].ToString()));
	Word_Edit[14]->UpdateString(PathSource::SystoStd(Beast[t]->Defense[3].ToString()));
	Word_Edit[16]->UpdateString(PathSource::SystoStd(Beast[t]->Cooldown[3].ToString() + "%"));
	Word_Edit[18]->UpdateString(BeastString[Beast[t]->Name]);
	//add row for powers
		
}

void GameModel::Bag::Draw(sf::RenderTarget& rt)
{
	switch (State) {
	case Window_Bag::Menu:
		rt.draw(*Sprite);
		for (int i = 0; i < Word->Count; i++) {
			Word[i]->Draw(rt);
		}
		break;
	case Window_Bag::Beasts:
		rt.draw(*Sprite);
		Word_Beast[0]->Draw(rt);
		Word_Beast[1]->Draw(rt);
		for (int j = 0; j < Beast->Count; j++) {
			//revisar posicion
			Beast[j]->CurrentAnimation = AnimationIndex::Idle;
			Beast[j]->Update();
			Beast[j]->Move(X, Y + Word_Beast[0]->Rect->getGlobalBounds().height + (j + 2) * (Height / 6));
			Beast[j]->Draw(rt);
			for (int i = 3*(j+1)-1; i < 3 * (j + 1)+2; i += 3) {
				//revisar posicion
				Word_Beast[i]->UpdateString(PathSource::SystoStd(Beast[j]->TagName));
				Word_Beast[i]->Move(Beast[j]->X + Beast[j]->Length + 20, Beast[j]->Y);
				Word_Beast[i + 1]->Move(Word_Beast[i]->X + Word_Beast[i]->Rect->getGlobalBounds().width+5, Beast[j]->Y - 15);
				Word_Beast[i + 2]->Move(Word_Beast[i]->X + Word_Beast[i]->Rect->getGlobalBounds().width + 5, Beast[j]->Y + 15);
				Word_Beast[i]->Draw(rt);
				Word_Beast[i + 1]->Draw(rt);
				Word_Beast[i + 2]->Draw(rt);
			}
		}
		break;
	case Items:
		rt.draw(*Sprite);
		Word_Item[0]->Draw(rt);
		Word_Item[1]->Draw(rt);
		break;
	case Setting:
		rt.draw(*Sprite);
		Word_Setting[0]->Draw(rt);
		Word_Setting[1]->Draw(rt);
		break;
	case Edit:
		rt.draw(*Sprite);
		Beast[System::Int16::Parse(Word_Edit[0]->T)]->Move(X + 20, Y + (2) * Height / 13+25);
		Beast[System::Int16::Parse(Word_Edit[0]->T)]->Draw(rt);
		for (int i = 1; i < Word_Edit->Count; i++) {
			Word_Edit[i]->Draw(rt);
		}
		Stat->Draw(rt);
	}
}

void GameModel::Bag::AddBeast(GameModel::Beast^ b)
{
	Beast->Add(b);
	GameView::Word^ n = gcnew GameView::Word(0,0, Beast[Beast->Count - 1]->TagName, 24, sf::Color::Red);
	GameView::Word^ n1 = gcnew GameView::Word(0, 0, "Edit", 24, sf::Color::Red);
	GameView::Word^ n2 = gcnew GameView::Word(0, 0, "Set Free", 24, sf::Color::Red);
	Word_Beast->Add(n);
	Word_Beast->Add(n1);
	Word_Beast->Add(n2);
}

void GameModel::Bag::Move(float x, float y)
{
	GameObject::Move(x, y);
	//Menu
	Word[0]->Move(X + Length / 2 - Word[0]->Rect->getGlobalBounds().width / 2, Y + 1 * (Height / 6) - Word[0]->Rect->getGlobalBounds().height);
	Word[1]->Move(X + 1 * (Length / 4) - Word[1]->Rect->getGlobalBounds().width / 2, Y + 2 * (Height / 6) - Word[1]->Rect->getGlobalBounds().height);
	Word[2]->Move(X + 3 * (Length / 4) - Word[2]->Rect->getGlobalBounds().width / 2, Y + 2 * (Height / 6) - Word[2]->Rect->getGlobalBounds().height);
	Word[3]->Move(X + Length / 2 - Word[3]->Rect->getGlobalBounds().width / 2, Y + 3 * (Height / 6) - Word[3]->Rect->getGlobalBounds().height);
	Word[4]->Move(X + Length / 2 - Word[4]->Rect->getGlobalBounds().width / 2, Y + 4 * (Height / 6) - Word[4]->Rect->getGlobalBounds().height);
	Word[5]->Move(X + Length / 2 - Word[5]->Rect->getGlobalBounds().width / 2, Y + 5 * (Height / 6) - Word[5]->Rect->getGlobalBounds().height);
	//Beast
	Word_Beast[0]->Move(X + Length / 2 - Word_Beast[0]->Rect->getGlobalBounds().width / 2, Y + 1 * (Height / 6) - Word_Beast[0]->Rect->getGlobalBounds().height);
	Word_Beast[1]->Move(X + 20, Y + 1 * (Height / 6) - Word_Beast[0]->Rect->getGlobalBounds().height);
	//Items
	Word_Item[0]->Move(X + Length / 2 - Word_Item[0]->Rect->getGlobalBounds().width / 2, Y + 1 * (Height / 6) - Word_Item[0]->Rect->getGlobalBounds().height);
	Word_Item[1]->Move(X + 20, Y + 1 * (Height / 6) - Word_Item[0]->Rect->getGlobalBounds().height);
	//Settings
	Word_Setting[0]->Move(X + Length / 2 - Word_Setting[0]->Rect->getGlobalBounds().width / 2, Y + 1 * (Height / 6) - Word_Setting[0]->Rect->getGlobalBounds().height);
	Word_Setting[1]->Move(X + 20, Y + 1 * (Height / 6) - Word_Setting[0]->Rect->getGlobalBounds().height);
	//Edit
	Word_Edit[1]->Move(X + 20, Y + (1) * Height / 13);
	Word_Edit[2]->Move(X + Length / 2, Y + (1) * Height / 13);
	Word_Edit[3]->Move(X + 50 + 40, Y + (2) * Height / 13);
	Word_Edit[4]->Move(X + 50 + 40 + Word_Edit[3]->Rect->getGlobalBounds().width, Y + (2) * Height / 13);
	Word_Edit[5]->Move(X + 50 + 40, Y + (3) * Height / 13);
	Word_Edit[6]->Move(X + 50 + 40 + Word_Edit[5]->Rect->getGlobalBounds().width, Y + (3) * Height / 13);
	Word_Edit[7]->Move(X + 50 + 40, Y + (4) * Height / 13);
	Word_Edit[8]->Move(X + 50 + 40 + Word_Edit[7]->Rect->getGlobalBounds().width, Y + (4) * Height / 13);
	Word_Edit[9]->Move(X + 20, Y + (5) * Height / 13);
	Word_Edit[10]->Move(X + 20 + Word_Edit[9]->Rect->getGlobalBounds().width, Y + (5) * Height / 13);
	Word_Edit[11]->Move(X + 20, Y + (6) * Height / 13);
	Word_Edit[12]->Move(X + 20 + Word_Edit[11]->Rect->getGlobalBounds().width, Y + (6) * Height / 13);
	Word_Edit[13]->Move(X + 20, Y + (7) * Height / 13);
	Word_Edit[14]->Move(X + 20 + Word_Edit[13]->Rect->getGlobalBounds().width, Y + (7) * Height / 13);
	Word_Edit[15]->Move(X + 20, Y + (8) * Height / 13);
	Word_Edit[16]->Move(X + 20 + Word_Edit[15]->Rect->getGlobalBounds().width, Y + (8) * Height / 13);
	Word_Edit[17]->Move(X + 20, Y + (9) * Height / 13);
	Word_Edit[18]->Move(X + 20 + Word_Edit[17]->Rect->getGlobalBounds().width, Y + (9) * Height / 13);
	if (Stat != nullptr) {
		Stat->Move(X + 350, Y + 300);
	}
}


