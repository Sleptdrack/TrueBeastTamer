#pragma once
#include "MessageBox.h"
#include "Screen.h"
#include "Tamer.h"
using namespace GameModel;
using namespace System::Collections::Generic;
namespace GameView {
	public ref class Tutorial {
	public:
		property Screen^ Screen;
		property List<Beast^>^ Beast;
		property Tamer^ T;
	public:
		Tutorial(Tamer^ t);
		void Draw();
		void ChooseBeast(bool* t);
		void DrawTutorial();
	};
}


