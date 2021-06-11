#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>

namespace GameView {
	public ref class Pause
	{
	public:
		property static bool m_flagPause;
		property static Screen^ Screen;
		static void MakeWindowsOnTop(sf::RenderWindow& windows);
		static void PrintWindows(bool & pause);
	};

}