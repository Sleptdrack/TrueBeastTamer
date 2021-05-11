#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "Word.h"
using namespace System::Collections::Generic;
namespace GameView {
	public ref class Screen{
	public:
		property List<Word^>^ Word;
		property float Length;
		property float Height;
		property sf::RectangleShape* Rect;
		property sf::Texture* Texture;
		property float X;
		property float Y;
	public:
		Screen(float x,float y,float l,float h);
		void Add(GameView::Word^ w);
		void Draw(RenderTarget& rt);
	};
}


