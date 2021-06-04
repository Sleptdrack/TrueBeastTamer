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
	static List<System::String^>^ Power = gcnew List<System::String^>();
	static List<int>^ Resolution = gcnew List<int>();
public:
	static std::string SystoStd(System::String^ t);
	static System::String^ StdtoSys(std::string t);
	static void LoadFromFile(std::string t);
};
public ref class WordSource {
public:
	static List<List<System::String^>^>^ Word = gcnew List<List<System::String^>^>();
public:
	static void LoadFromFile(std::string t);
};
public ref class BeastSource {
public:
	static List<System::String^>^ Sprite = gcnew List<System::String^>();
	static List<System::String^>^ Sound = gcnew List<System::String^>();
	static List<float>^ Health = gcnew List<float>();
	static List<float>^ Defense = gcnew List<float>();
	static List<float>^ Attack = gcnew List<float>();
	static List<float>^ Cooldown = gcnew List<float>();
public:
	static void LoadFromFile(std::string t);
};
