#pragma once
#include <SFML/Graphics.hpp>
using namespace System;
using namespace System::Collections::Generic;
using namespace sf;
namespace GameModel {
	public ref class GameObject {
	public:
		Sprite* Sprite = new sf::Sprite();
		Texture* Texture = new sf::Texture();
		property float Size;
		property float X;
		property float Y;
	public:
		GameObject();
		void Draw(RenderTarget& rt);
	};
}
