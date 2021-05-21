#pragma once
#include "Screen.h"
namespace GameView {
	public ref class MessageBox{
	public:
		property static Screen^ Screen;
	public:
		static void Show(System::String^ n);
	};
}


