#include "pch.h"
#include "Music.h"

void GameView::Music::Load()
{
	Click->loadFromFile(PathSource::SystoStd(PathSource::Word[1]));
	Sound->setBuffer(*Click);
	Login->openFromFile("../Sound/Pausesound.ogg");
	Login->setLoop(true);
	Login->pause();
}

void GameView::Music::SetVolume(float v)
{
	Login->setVolume(v);
	Sound->setVolume(v);
}

void GameView::Music::ClickSound()
{
	Sound->play();
}
