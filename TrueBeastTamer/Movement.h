#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
using namespace System;
using namespace GameModel;
using namespace sf;
namespace GameController {
	public ref class Movement{
	public:
		static void Move(GameObject^ G, Time t);
		static void Move(GameObject^ G, Time t, RectangleShape* R);
		static void Movement::MoveAttack(GameObject^ G, Time t);
	};
}


