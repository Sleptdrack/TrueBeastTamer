#pragma once
#include "GameObject.h"
#include "Bag.h"
namespace GameModel {
    public ref class Tamer :public GameObject {
	public:
		property sf::String* Username;
		property sf::String* Password;
		property int NumBeast;
		property Bag^ Bag;
	public:
		Tamer(sf::String U,sf::String P);
    };
}

