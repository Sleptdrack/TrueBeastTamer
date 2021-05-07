#pragma once
#include "GameObject.h"
#include "Grass.h"
using namespace System::Collections::Generic;
ref class Garden : public GameObject{
public:
	property float GrassSize;
	property int Size;
	property List<Grass^>^ ListGrass;
public:
	Garden(float x, float y, int size);
	void Draw(RenderTarget& rt);
	bool Contains(GameObject^ G);
};

