#include "pch.h"
#include "Garden.h"
GameModel::Garden::Garden(float x, float y, int size){
    Grass = gcnew List<GameModel::Grass^>();
    LBeast = gcnew List<Beast^>();
    X = x;
    Y = y;
    Size = size;
    for (int i = 0; i < Size; i++) {
        for (int u = 0; u < Size; u++) {
            GameModel::Grass^ gr = gcnew GameModel::Grass();
            gr->Move(i * gr->Length + X, u * gr->Height + Y);
            Grass->Add(gr);
        }
    }
    Length = Size * TileSize;
    Height = Size * TileSize;
}
void GameModel::Garden::Draw(RenderTarget& rt){
    for (int i = 0; i < Grass->Count; i++) {
        Grass[i]->Draw(rt);
    }
    for (int i = 0; i < LBeast->Count; i++) {
        LBeast[i]->Draw(rt);
    }
}
bool GameModel::Garden::Contains(GameObject^ G){
    bool f = false;
    for (int i = 0; i < Grass->Count; i++) {
        if (Grass[i]->Contains(G)) {
            f = true;
        }
    }
    return f;
}
void GameModel::Garden::Spawn(Tamer^ T,bool *t){
    int r = rand() % 100;
    int v = 0;
    for (int i = 0; i < Grass->Count; i++) {
        v = 0;
        if (Grass[i]->Contains(T) && r<= Grass[i]->SpawnRate && *t==false) {
            *t = true;
            Beast^ b = gcnew Beast(static_cast<BeastName>(rand()%6));//provisionalmente Trululu
            b->Move(Grass[i]->X, Grass[i]->Y);
            for (int j = 0; j < LBeast->Count; j++) {
                if (LBeast[j]->X == b->X && LBeast[j]->Y == b->Y) {
                    v += 1;
                }
            }
            if (v == 0) {
                LBeast->Add(b);
            }
        }
    }
}
