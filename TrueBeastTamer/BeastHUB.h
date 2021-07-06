#pragma once
#include <SFML/Graphics.hpp>
#include "Beast.h"

using namespace GameModel;

namespace GameView {
	[Serializable]
	public ref class BeastHUB {
	public:
		property sf::Texture* expT;
		property sf::Texture* hpT;
		property sf::Texture* hubT;
		property sf::Sprite* Exp;
		property sf::Sprite* Hp;
		property sf::Sprite* HUB;
		property float X;
		property float Y;
	public:
		void setDrawables(sf::String h, sf::String e, sf::String m);
		void Draw(RenderTarget& rt);
		BeastHUB(float x, float y, Beast^ G);
		void Update(Beast^ G);
	};
}


