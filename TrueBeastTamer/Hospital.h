#pragma once
#include "GameObject.h"
#include "NPC.h"
namespace GameModel {
	public ref class Hospital : public GameObject {//crear ventana
	public:
		property NPC^ Nurse;
	public:
		Hospital(float x, float y);
	};
}