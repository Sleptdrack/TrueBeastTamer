#pragma once
#include <SFML/Graphics.hpp>
const float TileSize = 50;
using namespace System::Collections::Generic;
using namespace sf;
namespace GameModel {
	public ref class GameObject {
	public:
		property Sprite* Sprite;
		property Texture* Texture;
		property float Height;
		property float Length;
		property float X;
		property float Y;
	public:
		GameObject();
		void Draw(RenderTarget& rt);
		void Move(float x, float y);
		bool Contains(float x, float y, float h, float l);
	};
	public ref class Arena : public GameObject {

	};
	public ref class Power {
	public:
		property int Type;//Water->Fire->Air->Ligthing->Earth->water; Neutral
		property int Range;
		property String* Name;
	public:
		Power();
	};
	public ref class Beast : public GameObject {
	public:
		property String* Name; // usaremos el String de la libreria SFML
		property int Type;
		property int Health;
		property int Defense;
		property int Attack;
		property int Speed;
		property int Level;
		property int Exp;
	public:
		Beast();
	};
	public ref class Bag : public GameObject {
	public:
		List<Beast^>^ ListBeast;
	public:
		Bag();
	};
	public ref class Tamer : public GameObject {
	public:
		property String* Username;
		property String* Password;
		property int NumBeast;
		property Bag^ Bag;
	public:
		Tamer(float x, float y);
	};
	public ref class NPC : public GameObject {
	public:
		property int Enemy;
	};
	public ref class Store : public GameObject {//crear ventana
	public:
		property NPC^ Salesman;
	public:
		Store(float x, float y);
	};
	public ref class Hospital : public GameObject {//crear ventana
	public:
		property NPC^ Nurse;
	public:
		Hospital(float x, float y);
	};
	public ref class Grass : public GameObject {
	public:
		property int SpawnRate;
	public:
		Grass();
	};
	public ref class Garden {
	public:
		property float GrassSize;
		property float X;
		property float Y;
		property int Size;
		property List<Grass^>^ Grass;
	public:
		Garden(float x, float y, int size);
		void Draw(RenderTarget& rt);
		bool Contains(float x, float y, float l, float h);
	};
	public ref class Obstacle :public GameObject {
	public:
		property bool Breakeable;
		property bool Harmful;
	};
	//aqui crear clases de obtaculos
	public ref class Map {
	public:
		property int NumGarden;
		property int NumNPC;
		property List<Obstacle^>^ Obstacle;
		property List<Garden^>^ Garden;
		property List<NPC^>^ NPC;
		property Hospital^ Hospital;
		property Store^ Store;
		property Tamer^ Player;
	public:
		Map(int ng, int nn);
		void Draw(RenderTarget& rt);
	};
}
