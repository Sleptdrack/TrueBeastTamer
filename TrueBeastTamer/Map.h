#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "Garden.h"
using namespace System::Collections::Generic;
using namespace sf;
namespace GameModel {
	public ref class Map {
	public:
		property int NumGarden;
		property int NumNPC;
		//property List<Obstacle^>^ Obstacle;
		property List<Garden^>^ Garden;
		//property List<NPC^>^ NPC;
		//property Hospital^ Hospital;
		//property Store^ Store;
		//property Tamer^ Player;
	public:
		Map(int ng, int nn);
		void Draw(RenderTarget& rt);
	};
}


