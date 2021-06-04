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
	Length = TileSize;
	Height = TileSize;
	Name = name;
	Power = gcnew List<GameModel::Power^>();
	GameModel::Power^ p = nullptr;
	switch (Name) {
	     case BeastName::Trululu: 
			 TagName = "Trululu";
			 Type = Element::Neutral;
			 p = gcnew GameModel::Power(Type, basic);
			 Power->Add(p);
			 BeastSource::LoadFromFile(PathSource::SystoStd(PathSource::Beast[0]));
			 SetDrawables(PathSource::SystoStd(BeastSource::Sprite[0]),
				 PathSource::SystoStd(BeastSource::Sound[0]),
				 PathSource::SystoStd(BeastSource::Sound[1]));
			 setStat(Health, BeastSource::Health[0], BeastSource::Health[1], BeastSource::Health[2]);
			 setStat(Defense, BeastSource::Defense[0], BeastSource::Defense[1], BeastSource::Defense[2]);
			 setStat(Attack, BeastSource::Attack[0], BeastSource::Attack[1], BeastSource::Attack[2]);
			 setStat(Cooldown, BeastSource::Cooldown[0], BeastSource::Cooldown[1], BeastSource::Cooldown[2]);
			 break;
		 case BeastName::Atropos: 
			 TagName = "Atropos";
			 Type = Element::Earth;
			 p = gcnew GameModel::Power(Type, basic);
			 Power->Add(p);
			 BeastSource::LoadFromFile(PathSource::SystoStd(PathSource::Beast[1]));
			 SetDrawables(PathSource::SystoStd(BeastSource::Sprite[0]),
				 PathSource::SystoStd(BeastSource::Sound[0]),
				 PathSource::SystoStd(BeastSource::Sound[1]));
			 setStat(Health, BeastSource::Health[0], BeastSource::Health[1], BeastSource::Health[2]);
			 setStat(Defense, BeastSource::Defense[0], BeastSource::Defense[1], BeastSource::Defense[2]);
			 setStat(Attack, BeastSource::Attack[0], BeastSource::Attack[1], BeastSource::Attack[2]);
			 setStat(Cooldown, BeastSource::Cooldown[0], BeastSource::Cooldown[1], BeastSource::Cooldown[2]);
			 break;
		 case BeastName::Quin: 
			 TagName = "Quin";
			 Type = Element::Water;
			 p = gcnew GameModel::Power(Type, basic);
			 Power->Add(p);
			 BeastSource::LoadFromFile(PathSource::SystoStd(PathSource::Beast[2]));
			 SetDrawables(PathSource::SystoStd(BeastSource::Sprite[0]),
				 PathSource::SystoStd(BeastSource::Sound[0]),
				 PathSource::SystoStd(BeastSource::Sound[1]));
			 setStat(Health, BeastSource::Health[0], BeastSource::Health[1], BeastSource::Health[2]);
			 setStat(Defense, BeastSource::Defense[0], BeastSource::Defense[1], BeastSource::Defense[2]);
			 setStat(Attack, BeastSource::Attack[0], BeastSource::Attack[1], BeastSource::Attack[2]);
			 setStat(Cooldown, BeastSource::Cooldown[0], BeastSource::Cooldown[1], BeastSource::Cooldown[2]);
			 break;
		 case BeastName::Mosfet: 
			 TagName = "Mosfet";
			 Type = Element::Ligthing;
			 p = gcnew GameModel::Power(Type, basic);
			 Power->Add(p);
			 BeastSource::LoadFromFile(PathSource::SystoStd(PathSource::Beast[3]));
			 SetDrawables(PathSource::SystoStd(BeastSource::Sprite[0]),
				 PathSource::SystoStd(BeastSource::Sound[0]),
				 PathSource::SystoStd(BeastSource::Sound[1]));
			 setStat(Health, BeastSource::Health[0], BeastSource::Health[1], BeastSource::Health[2]);
			 setStat(Defense, BeastSource::Defense[0], BeastSource::Defense[1], BeastSource::Defense[2]);
			 setStat(Attack, BeastSource::Attack[0], BeastSource::Attack[1], BeastSource::Attack[2]);
			 setStat(Cooldown, BeastSource::Cooldown[0], BeastSource::Cooldown[1], BeastSource::Cooldown[2]);
			 break; 
	}
}

void GameModel::Beast::SetDrawables(sf::String s, sf::String a1, sf::String a2)
{
	GameObject::setDrawables(s);
	Power[0]->SHit = new sf::SoundBuffer();
	Power[0]->SMove = new sf::SoundBuffer();
	Power[0]->Hit = new sf::Sound();
	Power[0]->Move = new sf::Sound();
	Power[0]->SHit->loadFromFile(a1);
	Power[0]->SMove->loadFromFile(a2);
	Power[0]->Hit->setBuffer(*Power[0]->SHit);
	Power[0]->Hit->setVolume(50);
	Power[0]->Move->setBuffer(*Power[0]->SMove);
	Power[0]->Move->setVolume(50);
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
