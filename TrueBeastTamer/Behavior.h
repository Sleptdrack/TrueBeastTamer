#pragma once
#include "Beast.h"
using namespace System;
namespace GameModel {
	[Serializable]
	public ref class Coords {
	public:
		property float x;
		property float y;
	public:
		Coords(float xx, float yy);
	};
	[Serializable]
	public ref class Behavior{
	public:
		static Coords^ Destiny = gcnew Coords(0,0);
		static bool DestinationReached = false;
		static bool Loaded = false;
	public:
		static void Load();
		static void Move(Beast^ G, Time t, RectangleShape* R, Beast^ B);
		static void Attack(Beast^ G, RectangleShape* R,Beast^ B);
		static void UpdateBehavior(Beast^ G);
	};
}
