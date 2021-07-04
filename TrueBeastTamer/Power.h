#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameObject.h"
using namespace System;
using namespace System::Collections::Generic;
typedef enum{basic,ss,sdf} Attack;//completar con mas ataques
namespace GameModel {
	[Serializable]
	public ref class Shot : public GameObject {
	public:
		property sf::Vector2f* start;
		property sf::Vector2f* end;
		property int destiny;
	public:
		Shot(sf::Vector2f e, sf::Vector2f s);
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
			property sf::SoundBuffer* SHit;
			property sf::SoundBuffer* SMove;
			property sf::Sound* Hit;
			property sf::Sound* Move;
	public:
		Power(Element t, Attack k);
		void Stop();
		

	};
}

