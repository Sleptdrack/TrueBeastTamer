#pragma once
#include "pch.h"

#include "GameObject.h"
using namespace System;
namespace GameModel {
	[Serializable]
	public ref class Obstacle : public GameObject{
		public:
			property bool Breakeable;
			property bool Harmful;
	};

}