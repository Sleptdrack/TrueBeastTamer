#include "pch.h"
#include "Animation.h"

Frame::Frame(float x, float  y, float  width, float  height) {
	X = x;
	Y = y;
	Width = width;
	Height = height;
}

Animate::Animate(float x, float y, float width, float height)
{
	nFrames = 3;
	iFrame = 0;
	ht = 1.0f;
	frame = gcnew List<Frame^>();
	for (int i = 0; i < nFrames; i++) {
		frame->Add(gcnew Frame(x + i * width, y, width, height));
	}

}

void Animate::Advance() {
	if (++iFrame >= nFrames) {
		iFrame = 0;
	}
	else {
		iFrame += 1;
	}
}

Animate::Animate(float x, float y, float width, float height, int f)
{
	nFrames = f;
	iFrame = 0;
	ht = 1.0f;
	frame = gcnew List<Frame^>();
	for (int i = 0; i < nFrames; i++) {
		frame->Add(gcnew Frame(x + i * width, y, width, height));
	}
}