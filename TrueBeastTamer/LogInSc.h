#pragma once
#include "Screen.h"
#include "Tamer.h"
#include "GameManager.h"
#include "Tamer.h"
namespace GameView {
	public ref class LogInSc {
	public:
		property Screen^ Screen;
		property System::String^ U;
		property System::String^ P;
		property Tamer^ T;
	public:
		LogInSc();
		void Fill(sf::Event e);
		void Draw();
		void Log(bool *r);
	};
}


