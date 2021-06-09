#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "GameManager.h"
using namespace System;
using namespace GameModel;
using namespace sf;
namespace GameController {
	public ref class Interraction{
	public:
		static void SetStateBag(Tamer^ T, RenderWindow& rt);
		static void MoveBag(Tamer^ T, RenderWindow& rt, sf::Vector2f* t);
		static void UsePower(Beast^ b, RenderWindow& rt);
	};
}

