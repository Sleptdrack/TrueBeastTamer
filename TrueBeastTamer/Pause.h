#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"
namespace GameModel {
	[Serializable]
	public ref class Pause: public GameModel::GameObject
	{
	public:
		property bool m_flagPause;
		property bool moving;
		property List<GameView::Word^>^ Word_Pause;
		property static sf::RectangleShape* Rect;
		Pause();
		void OpenPause(bool pause);
		void SelectOption(RenderWindow& rt, bool& pause);
		void DrawPause(sf::RenderTarget& rt);
		void setDrawables(sf::String t);
		void Move(float x, float y);
		
	};

}