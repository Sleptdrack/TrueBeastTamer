#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "Garden.h"
using namespace System::Collections::Generic;
using namespace sf;
public ref class Map{
public:
	property int NumGarden;
	property int NumNPC;
	//property List<Obstacle^>^ Obstacle_;
	property List<Garden^>^ LGarden;
	//property List<NPC^>^ NPC_;
	//property Hospital^ Hospital_;
	//property Store^ Store_;
	//property Tamer^ Player;
public:
	Map(int ng, int nn);
	void Draw(RenderTarget& rt);
};

