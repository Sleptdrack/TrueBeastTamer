#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace System;
using namespace System::Collections::Generic;
typedef enum AnimationIndex
{
	WalkingRight,
	WalkingLeft,
	WalkingDown,
	WalkingUp,
	Idle,
	Count,
};
[Serializable]
public ref class Frame {
public:
	property float X;
	property float Y;
	property float Width;
	property float Height;
public:
	Frame(float x, float y, float  width, float  height);
};
[Serializable]
public ref class Animate {
public:
	property int nFrames;
	property int iFrame;
	property float ht;
	property List<Frame^>^ frame;
public:
	Animate(float x, float y, float  width, float  height);
	Animate(float x, float y, float  width, float  height, int f);
	void Advance();
};