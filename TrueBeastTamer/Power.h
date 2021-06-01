#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"
using namespace System;
using namespace System::Collections::Generic;
typedef enum{basic,ss,sdf} Attack;//completar con mas ataques
namespace GameModel {
	[Serializable]
	public ref class Shot : public GameObject {
	public:
		property sf::Vector2i* start;
		property sf::Vector2i* end;
		property int destiny;
	public:
		Shot(sf::Vector2i e, sf::Vector2i s);
		void setDrawable(sf::String n);
	};
	[Serializable]
	public ref class Power
	{
		public:
			property Element Type;
			property int Range;
			property Attack Kind;
			property List<Shot^>^ Shot;
			property int cooldown;
			property bool InUse;
	public:
		Power(Element t, Attack k);
		

	};
}

