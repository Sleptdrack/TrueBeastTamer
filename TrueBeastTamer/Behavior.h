#pragma once
typedef enum {Calm, Annoyed, Angry, Mad, Furious} Beast_State;
using namespace System;
namespace GameModel {
	[Serializable]
	public ref class Behavior
	{
		public:
			static Beast_State State;



	};
}
