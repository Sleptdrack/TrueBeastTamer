#pragma once
#include "Beast.h"
using namespace System;
using namespace System::Collections::Generic;
namespace GameModel {
	[Serializable]
	public ref class Trululu :public Beast{
	public:
		Trululu(float x, float y);
	};
}


