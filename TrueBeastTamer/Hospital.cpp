#include "pch.h"
#include "Hospital.h"

GameModel::Hospital::Hospital(float x, float y) {
    Nurse = gcnew NPC();
    X = x;
    Y = y;
    Length = 100;
    Height = 100;
    FrameSize = 160;
    setDrawables(PathSource::SystoStd(PathSource::Hospital[0]));
    HealthObj = gcnew GameModel::Health();
}

void GameModel::Hospital::Draw(RenderTarget& rt)
{
    rt.draw(*Sprite);
    HealthObj->DrawPause(rt);
}

