#pragma once
#include "GameObject.h"
#include "NPC.h"
using namespace System;
namespace GameModel {
	[Serializable]
	public ref class Hospital : public GameObject {//crear ventana
	public:
		property NPC^ Nurse;
	public:
		Hospital(float x, float y);
	};
}