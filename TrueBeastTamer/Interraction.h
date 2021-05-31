#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
using namespace System;
using namespace GameModel;
using namespace sf;
namespace GameController {
	public ref class Interraction{
	public:
		static void SetStateBag(Tamer^ T, RenderWindow& rt);
	};
}

