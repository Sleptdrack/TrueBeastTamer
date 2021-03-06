#pragma once
#include "GameObject.h"
#include "Grass.h"
#include "Beast.h"
#include "Tamer.h"
using namespace System::Collections::Generic;
using namespace System;
namespace GameModel {
	[Serializable]
	public ref class Garden : public GameObject {
	public:
		property float GrassSize;
		property int Size;
		property List<Grass^>^ Grass;
		property List<Beast^>^ LBeast;
	public:
		Garden(float x, float y, int size);
		void Draw(RenderTarget& rt);
		bool Contains(GameObject^ G);
		void Spawn(Tamer^ T,bool *t);
	};

}

