#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
const float TileSize = 50;
using namespace System::Collections::Generic;
using namespace sf;
namespace GameModel {
	public ref class GameObject {
	public:
		property Sprite* Sprite;
		property Texture* Texture;
		property float Height;
		property float Length;
		property float X;
		property float Y;
		property float Speed;
	public:
		GameObject();
		void Draw(RenderTarget& rt);
		void Move(float x, float y);
		bool Contains(GameObject^ G);
	};
}