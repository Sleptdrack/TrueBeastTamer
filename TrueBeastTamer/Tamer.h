#pragma once
#include "GameObject.h"
#include "Bag.h"
using namespace System;
namespace GameModel {
	[Serializable]
    public ref class Tamer :public GameObject {
	public:
		property int Id;
		property sf::String* Username;
		property sf::String* Password;
		property int NumBeast;
		property Bag^ Bag;
	public:
		Tamer(sf::String U,sf::String P,int id);
    };
}

