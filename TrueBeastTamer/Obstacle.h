#pragma once
#include "pch.h"

#include "GameObject.h"
namespace GameModel {
	ref class Obstacle : public GameObject
	{
		public:
			bool Breakeable;
			bool Harmful;
	};

}