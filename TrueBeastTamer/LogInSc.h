#pragma once
#include "Screen.h"
namespace GameView {
	public ref class LogInSc {
	public:
		property sf::RenderWindow* W;
		property Screen^ Screen;
		property sf::String* U;
		property sf::String* P;
	public:
		LogInSc();
		void Fill(sf::Event e);
		void Draw();
		void Log(bool *r);
	};
}


