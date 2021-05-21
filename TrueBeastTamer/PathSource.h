#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace System::Collections::Generic;
public ref class PathSource{
public:
	static List<System::String^>^ Tamer = gcnew List<System::String^>();
	static List<System::String^>^ Beast = gcnew List<System::String^>();
	static List<System::String^>^ Word = gcnew List<System::String^>();
	static List<System::String^>^ Bag = gcnew List<System::String^>();
	static List<System::String^>^ Grass = gcnew List<System::String^>();
	static List<System::String^>^ Hospital = gcnew List<System::String^>();
public:
	static std::string SystoStd(System::String^ t);
	static System::String^ StdtoSys(std::string t);
	static void LoadFromFile(std::string t);
};

