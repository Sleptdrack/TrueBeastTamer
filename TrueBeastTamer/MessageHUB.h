#pragma once
#include <SFML/Graphics.hpp>
#include "Word.h"
#include "GameObject.h"

using namespace System::Collections::Generic;
namespace GameView {
	[Serializable]
	public ref class MessageHUB: GameModel::GameObject {
	public:
		property  sf::Sprite* Sprite;
		property sf::Texture* Texture;
		property List<GameView::Word^>^ Word;
		property float X;
		property float Y;
		property float Width;
		property float Heigth;
	public:
		MessageHUB(System::String^ t);
		void setDrawables(sf::String t);
		void Stay(bool* p, RenderWindow &rt);
		void Draw(RenderTarget& rt);
		void Move(float x, float y);

	};
}


