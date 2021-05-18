#pragma once
#include "Tamer.h"
using namespace GameModel;
using namespace System::Collections::Generic;
namespace GameController {
	public ref class GameManager{
	public:
		static List<Tamer^>^ Player = gcnew List<Tamer^>();
	public:
		//autentificacion
		static Tamer^ ValidatePlayer(sf::String u, sf::String p);

		static List<Tamer^>^ QueryPlayers();
		static void AddPlayer(Tamer^ T);
	};
}


