#pragma once
#include "GameObject.h"
using namespace System;
namespace GameModel {
	[Serializable]
	public ref class Grass : public GameObject {
	public:
		property int SpawnRate;
	public:
		Grass();
	};
}


