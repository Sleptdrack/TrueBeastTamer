#include "pch.h"
#include "Health.h"

GameModel::Health::Health()
{
	Length = 300;
	Height = 200;
	X = 400;
	Y = 250;

	Word_Health = gcnew List<GameView::Word^>();
	GameView::Word^ Message = gcnew GameView::Word(0, 0, "Healt Option", 31, sf::Color(52, 101, 248, 255));
	Message->Move(X + Length / 2 - Message->Rect->getGlobalBounds().width / 2, Y + 2 * (Height / 6) - Message->Rect->getGlobalBounds().height);

	GameView::Word^ E1 = gcnew GameView::Word(0, 0, "Yes", 28, sf::Color(240, 240, 240, 255));
	E1->Move(X + 1 * (Length / 4) - E1->Rect->getGlobalBounds().width / 2, Y + 4 * (Height / 6) - E1->Rect->getGlobalBounds().height);

	GameView::Word^ E2 = gcnew GameView::Word(0, 0, "Not", 28, sf::Color(240, 240, 240, 255));
	E2->Move(X + 3 * (Length / 4) - E2->Rect->getGlobalBounds().width / 2, Y + 4 * (Height / 6) - E2->Rect->getGlobalBounds().height);


	Word_Health->Add(Message);
	Word_Health->Add(E1);
	Word_Health->Add(E2);

	setDrawables(PathSource::SystoStd(PathSource::Bag[0]));
}

void GameModel::Health::OpenHealth(bool pause)
{
	m_flagHealth = pause;
}

void GameModel::Health::SelectOption(RenderWindow& rt)
{
	if (m_flagHealth == true) {
		if (Word_Health[1]->Click(rt)) {
			// Make some option for live
			//HealUp
			m_flagHealth = false;
		}
		if (Word_Health[2]->Click(rt))
		{
			// Make some option for live
			m_flagHealth = false;
		}
	}
}

void GameModel::Health::DrawPause(sf::RenderTarget& rt)
{
	if (m_flagHealth == true) {
		rt.draw(*Sprite);
		for (int i = 0; i < Word_Health->Count; i++) {
			Word_Health[i]->Draw(rt);
		}
	}
}

void GameModel::Health::setDrawables(sf::String t)
{
	GameObject::setDrawables(PathSource::SystoStd(PathSource::Bag[0]));
	Rect = new RectangleShape(sf::Vector2f(Length / 2, Height / 25));
	Rect->setPosition(X, Y);
	Sprite->setColor(sf::Color(100, 200, 125, 255));
	for (int i = 0; i < Word_Health->Count; i++) {
		Word_Health[i]->SetParameters(PathSource::SystoStd(PathSource::Word[0]), PathSource::SystoStd(PathSource::Word[1]), Word_Health[i]->Code);
	}
}

void GameModel::Health::Move(float x, float y)
{
	GameObject::Move(x, y);

	Word_Health[0]->Move(X + Length / 2 - Word_Health[0]->Rect->getGlobalBounds().width / 2, Y + 2 * (Height / 6) - Word_Health[0]->Rect->getGlobalBounds().height);
	Word_Health[1]->Move(X + 1* Length / 4 - Word_Health[1]->Rect->getGlobalBounds().width / 2, Y + 4 * (Height / 6) - Word_Health[1]->Rect->getGlobalBounds().height);
	Word_Health[2]->Move(X + 3* Length / 4 - Word_Health[2]->Rect->getGlobalBounds().width / 2, Y + 4 * (Height / 6) - Word_Health[2]->Rect->getGlobalBounds().height);
}
