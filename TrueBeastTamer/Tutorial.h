#pragma once
#include "MessageBox.h"
#include "Screen.h"
#include "Tamer.h"
using namespace GameModel;
namespace GameView {
	public ref class Tutorial {
	public:
		property Screen^ Screen;
		property Tamer^ T;
	public:
		Tutorial(Tamer^ t);
	};
}


