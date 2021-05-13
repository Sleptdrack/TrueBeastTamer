#pragma once
#include "Screen.h"
#include "Tamer.h"
#include "GameManager.h"
#include "Tamer.h"
namespace GameView {
	public ref class LogInSc {
	public:
		property Screen^ Screen;
		property sf::String* U;
		property sf::String* P;
		property Tamer^ T;
	public:
		LogInSc();
		void Fill(sf::Event e);
		void Draw();
		void Log(bool *r);
	};
}


