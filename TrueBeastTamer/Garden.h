#pragma once
#include "GameObject.h"
#include "Grass.h"
using namespace System::Collections::Generic;
namespace GameModel {
	public ref class Garden : public GameObject {
	public:
		property float GrassSize;
		property int Size;
		property List<Grass^>^ Grass;
	public:
		Garden(float x, float y, int size);
		void Draw(RenderTarget& rt);
		bool Contains(GameObject^ G);
	};

}

