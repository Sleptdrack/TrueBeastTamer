#pragma once
#include "Tamer.h"
#include "MessageBox.h"
#include "PathSource.h"
using namespace GameModel;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
namespace GameController {
	[Serializable]
	public ref class GameManager{
	public:
		static List<Tamer^>^ Player = gcnew List<Tamer^>();
	public:
		//autentificacion
		static Tamer^ ValidatePlayer(System::String^ u, System::String^ p);

		static List<Tamer^>^ QueryPlayers();
		static Tamer^ CreateTamer(System::String^ u, System::String^ p);
		static void AddPlayer(Tamer^ T);
		static void UpdatePlayer(Tamer^ T);
		static void SavePlayers();
		static void LoadPlayers();
	};
}


