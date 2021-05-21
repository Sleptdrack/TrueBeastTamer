#include "pch.h"
#include "Grass.h"

GameModel::Grass::Grass(){
    SpawnRate = 10;
    Height = TileSize;
    Length = TileSize;
    X = 0;
    Y = 0;
    setDrawables(PathSource::SystoStd(PathSource::Grass[0]));
}
