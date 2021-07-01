#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"
namespace GameModel {
	[Serializable]
	ref class Health : public GameModel::GameObject
	{
	public:
		property bool m_flagHealth;
		property bool m_flagHealth2;
		property bool moving;
		property List<GameView::Word^>^ Word_Health;
		property static sf::RectangleShape* Rect;
		Health();
		void OpenHealth(bool pause);
		void SelectOption(RenderWindow& rt, bool& life);
		void DrawPause(sf::RenderTarget& rt);
		void setDrawables(sf::String t);
		void Move(float x, float y);
	};
}

