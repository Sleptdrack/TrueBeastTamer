#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
using namespace System;
namespace GameModel {
	[Serializable]
	public ref class Power
	{
		public:
			property int Type;
			property int Range;
			property sf::String* Name;

	};
}

