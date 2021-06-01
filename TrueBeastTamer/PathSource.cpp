#include "pch.h"
#include "PathSource.h"
#include <msclr\marshal_cppstd.h>
std::string PathSource::SystoStd(System::String^ t)
{
	return msclr::interop::marshal_as<std::string>(t);
}

System::String^ PathSource::StdtoSys(std::string t)
{
	return msclr::interop::marshal_as<System::String^>(t);
}

void PathSource::LoadFromFile(std::string t)
{
	std::string line;
	std::ifstream myfile(t);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			List<int>^ n = gcnew List<int>();
			for (int i = 0; i < line.size(); i++) {
				if (line[i] == ';') {
					n->Add(i);
				}
			}
			if (line.substr(0, n[0]) == "Tamer") {
				for (int i = 0; i < n->Count - 1; i++) {
					Tamer->Add(StdtoSys(line.substr(n[i] + 1, n[i + 1] - n[i] - 1)));
				}
			}
			if (line.substr(0, n[0]) == "Word") {
				for (int i = 0; i < n->Count - 1; i++) {
					Word->Add(StdtoSys(line.substr(n[i] + 1, n[i + 1] - n[i] - 1)));
				}
			}
			if (line.substr(0, n[0]) == "Bag") {
				for (int i = 0; i < n->Count - 1; i++) {
					Bag->Add(StdtoSys(line.substr(n[i] + 1, n[i + 1] - n[i] - 1)));
				}
			}
			if (line.substr(0, n[0]) == "Beast") {
				for (int i = 0; i < n->Count - 1; i++) {
					Beast->Add(StdtoSys(line.substr(n[i] + 1, n[i + 1] - n[i] - 1)));
				}
			}
			if (line.substr(0, n[0]) == "Grass") {
				for (int i = 0; i < n->Count - 1; i++) {
					Grass->Add(StdtoSys(line.substr(n[i] + 1, n[i + 1] - n[i] - 1)));
				}
			}
			if (line.substr(0, n[0]) == "Hospital") {
				for (int i = 0; i < n->Count - 1; i++) {
					Hospital->Add(StdtoSys(line.substr(n[i] + 1, n[i + 1] - n[i] - 1)));
				}
			}
			if (line.substr(0, n[0]) == "Power") {
				for (int i = 0; i < n->Count - 1; i++) {
					Power->Add(StdtoSys(line.substr(n[i] + 1, n[i + 1] - n[i] - 1)));
				}
			}
		}
		myfile.close();
	}
	else std::cout << "Unable to open path";
}
