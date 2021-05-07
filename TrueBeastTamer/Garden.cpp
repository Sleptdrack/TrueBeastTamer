#include "pch.h"
#include "Garden.h"
Garden::Garden(float x, float y, int size){
    ListGrass = gcnew List<Grass^>();
    X = x;
    Y = y;
    Size = size;
    for (int i = 0; i < Size; i++) {
        for (int u = 0; u < Size; u++) {
            Grass^ gr = gcnew Grass();
            gr->Move(i * gr->Length + X, u * gr->Height + Y);
            ListGrass->Add(gr);
        }
    }
    Length = Size * TileSize;
    Height = Size * TileSize;
}
void Garden::Draw(RenderTarget& rt){
    for (int i = 0; i < ListGrass->Count; i++) {
        ListGrass[i]->Draw(rt);
    }
}
bool Garden::Contains(GameObject^ G){
    bool f = false;
    for (int i = 0; i < ListGrass->Count; i++) {
        if (ListGrass[i]->Contains(G)) {
            f = true;
        }
    }
    return f;
}
