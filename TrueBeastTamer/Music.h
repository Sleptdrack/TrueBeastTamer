#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "PathSource.h"
namespace GameView {
	public ref class Music{
	public:
		static sf::SoundBuffer* Click = new sf::SoundBuffer();
		static sf::Music* Login = new sf::Music();
		static sf::Sound* Sound = new sf::Sound();
	public:
		static void Load();
		static void SetVolume(float v);
		static void ClickSound();
	};
}


