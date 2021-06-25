#pragma once
#include "Beast.h"
#include "Word.h"
using namespace System::Collections::Generic;
namespace GameView {
	[Serializable]
	public ref class Stat{
	public:
		property sf::ConvexShape* base;
		property sf::ConvexShape* exent;
		property sf::ConvexShape* real;
		property List<Word^>^ Word;
		property float X;
		property float Y;
	public:
		Stat(GameModel::Beast^ B);
		void Move(float x, float y);
		void Draw(sf::RenderTarget& rt);
		void Scale(float x, float y);
	};
}


