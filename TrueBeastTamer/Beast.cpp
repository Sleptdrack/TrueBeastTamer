#include "pch.h"
#include "Beast.h"

GameModel::Beast::Beast(BeastName name)
{ 
	TagName = gcnew System::String("");
	Type = Element::Neutral;
	Health = gcnew List<float>();
	Defense = gcnew List<float>();
	Attack = gcnew List<float>();
	Cooldown = gcnew List<float>();
	Speed = 2;
	Level = 1;
	Exp = 0;
	X = 0;
	Y = 0;
	//esta parte debe ser borrada cuando se creen las subclases
	Length = TileSize;
	Height = TileSize;
	Name = name;
	switch (Name) {
	     case BeastName::Trululu: 
			 TagName = "Trululu";
			 Type = Element::Neutral;
			 setDrawables(PathSource::SystoStd(PathSource::Beast[0]));
			 setStat(Health, 30, 10, 0.75);
			 setStat(Defense, 3, 5, 0.5);
			 setStat(Attack, 5, 3, 0.5);
			 setStat(Cooldown, 10, 10, 3/5);
			 break;
		 case BeastName::Atropos: 
			 TagName = "Atropos";
			 Type = Element::Earth;
			 setDrawables(PathSource::SystoStd(PathSource::Beast[1]));
			 setStat(Health, 33, 10, 0.75);
			 setStat(Defense, 5, 6, 0.5);
			 setStat(Attack, 4, 3, 0.5);
			 setStat(Cooldown, 10, 10, 3 / 5);
			 break;
		 case BeastName::Quin: 
			 TagName = "Quin";
			 Type = Element::Water;
			 setDrawables(PathSource::SystoStd(PathSource::Beast[2]));
			 setStat(Health, 30, 10, 0.75);
			 setStat(Defense, 2, 5, 0.5);
			 setStat(Attack, 5.5, 3, 0.5);
			 setStat(Cooldown, 10, 10, 3 / 5);
			 break;
		 case BeastName::Mosfet: 
			 TagName = "Mosfet";
			 Type = Element::Ligthing;
			 setDrawables(PathSource::SystoStd(PathSource::Beast[3]));
			 setStat(Health, 28, 10, 0.75);
			 setStat(Defense, 3, 5, 0.5);
			 setStat(Attack, 7, 3, 0.5);
			 setStat(Cooldown, 10, 10, 3 / 5);
			 break; 
	}
	Power = gcnew List<GameModel::Power^>();
	GameModel::Power^ p=gcnew GameModel::Power(Type,basic);
	Power->Add(p);
}


void GameModel::Beast::Learn()
{
	throw gcnew System::NotImplementedException();
}

void GameModel::Beast::LevelUp()
{
	if (Exp > 100) {
		Level += 1;
		Exp -= 100;
		UpdateStats(Health, Level);
		UpdateStats(Defense, Level);
		UpdateStats(Attack, Level);
		UpdateStats(Cooldown, Level);
	}
}

void GameModel::Beast::UpdateStats(List<float>^ T,int L)
{
	T[2] = (T[0] + T[1]) * (1 - pow(T[4], L)) / (1 - T[4]);
}

//codigo de GC
void GameModel::Beast::setStat(List<float>^ s, float base, float particularidad, float radio)
{
	s->Add(base);//valor base
	s->Add(rand() % (int)particularidad);//valor particular
	s->Add(s[0] + s[1]);//valor max actual
	s->Add(s[2]);//valor actual
	s->Add(radio);//razon de cambio
}
