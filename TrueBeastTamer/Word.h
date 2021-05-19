#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <msclr\marshal_cppstd.h>
using namespace msclr::interop;
using namespace sf;
using namespace System;
namespace GameView {
	[Serializable]
	public ref class Word{
	public:
		property Font* Font;
		property sf::Text* Text;
		property sf::RectangleShape* Rect;
		property int Size;
		property Color* Color;
		property float X;
		property float Y;
		property sf::SoundBuffer* SB;
		property sf::Sound* S;
		property bool on;
	public:
		Word(float x,float y,System::String^ T, int size,sf::Color c);
		void Draw(sf::RenderTarget& rt);
		void Move(float x, float y);
		bool Click(sf::RenderWindow& rt);
		void UpdateString(System::String^ T);
		void Fill(sf::Event e, System::String^ U);
		void RectColor(sf::Color c);
	};
}


