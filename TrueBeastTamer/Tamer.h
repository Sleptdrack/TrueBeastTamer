#pragma once
#include "GameObject.h"
#include "Bag.h"
using namespace System;
namespace GameModel {
	[Serializable]
    public ref class Tamer :public GameObject {
	public:
		property int Id;
		property System::String^ Username;
		property System::String^ Password;
		property int NumBeast;
		property Bag^ Bag;
	public:
		Tamer(System::String^ U,System::String^ P,int id);
		void OpenBag();
		void Draw(RenderTarget& rt);
    };
}

