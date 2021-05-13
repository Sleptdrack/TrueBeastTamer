#pragma once
#include "Tamer.h"
using namespace GameModel;
namespace GameController {
	public ref class GameManager{
	public:
		//autentificacion
		static Tamer^ ValidatePlayer(sf::String u, sf::String p);
	};
}


