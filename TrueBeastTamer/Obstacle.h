#pragma once
#include "pch.h"

#include "GameObject.h"
namespace GameModel {
	public ref class Obstacle : public GameObject{
		public:
			property bool Breakeable;
			property bool Harmful;
	};

}