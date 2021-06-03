#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "Garden.h"
#include "Hospital.h"
#include "Tamer.h"
using namespace System::Collections::Generic;
using namespace System;
using namespace sf;
namespace GameModel {
	[Serializable]
	public ref class Map {
	public:
		property int NumGarden;
		property int NumNPC;
		//property List<Obstacle^>^ Obstacle;
		property List<Garden^>^ Garden;
		//property List<NPC^>^ NPC;
		property Hospital^ Hospital;
		//property Store^ Store;
		property Tamer^ Player;
	public:
		Map(int ng, int nn,Tamer^ p);
		void Draw(RenderTarget& rt);
	};
}


