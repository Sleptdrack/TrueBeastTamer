#pragma once
#include "GameObject.h"
#include "NPC.h"
#include "Health.h"
using namespace System;
namespace GameModel {
	[Serializable]
	public ref class Hospital : public GameObject {//crear ventana
	public:
		property NPC^ Nurse;
		property Health^ HealthObj;
	public:
		Hospital(float x, float y);
		void Draw(RenderTarget& rt);
	};

	
}