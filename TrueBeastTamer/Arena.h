#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "GameObject.h"
#include "Screen.h"
#include "Map.h"
#include "Beast.h"
#include "Movement.h"
using namespace GameController;
using namespace System;
using namespace GameView;
namespace GameModel {
	[Serializable]
	public ref class Arena: public GameObject{
	public:
		property Screen^ Screen;
		property RectangleShape* Tspace;
		property Beast^ B;

	public:
		Arena(Beast^ b);
		void Draw();
		void Show(Map^ M);
	};
}


