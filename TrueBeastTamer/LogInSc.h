#pragma once
#include "Screen.h"
namespace GameView {
	public ref class LogInSc {
	public:
		property Screen^ Screen;
		property sf::String* U;
		property sf::String* P;
	public:
		LogInSc();
		void Fill(sf::Event e, sf::RenderWindow&w);
		void Draw(sf::RenderTarget &r);
	};
}


