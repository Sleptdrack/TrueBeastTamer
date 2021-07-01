#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Arena.h"
using namespace System;
using namespace GameModel;
using namespace sf;
namespace GameController {
	public ref class Fight {
	public:
		static void Hunt(Map^ M, Arena^ A, RenderWindow& W);
		static void Battle(Beast^ B,Tamer^ T,int c);
	};
}

