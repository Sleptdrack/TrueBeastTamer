#include "pch.h"
#include "Map.h"

GameModel::Map::Map(int ng, int nn,Tamer^ p){
    Player = p;
    NumGarden = ng;
    NumNPC = nn;
    //Obstacle = gcnew List<Obstacle^>();
    Garden = gcnew List<GameModel::Garden^>();
    //Algoritmo para ubicar garden
    for (int i = 0; i < NumGarden; i++) {
        int F;
        int p = rand() % 3 + 3;//Tamaño de garden
        int x, y;
        do {
            F = 0;
            x = rand() % (1920 - (int)(p * TileSize));//posicion X
            y = rand() % (1080 - (int)(p * TileSize));//posicion Y
            GameModel::Garden^ gr = gcnew GameModel::Garden((float)x, (float)y, p);
            for (int u = 0; u < Garden->Count; u++) {
                if (Garden[u]->Contains(gr)) {
                    F += 1;
                }
            }
            if (F == 0) {
                Garden->Add(gr);
            }
        } while (F > 0);
    }
    //NPC = gcnew List<NPC^>();
    //Algoritmo para Hospital
    Hospital = gcnew GameModel::Hospital(0,0);
    Weapon = gcnew GameModel::Attack(30, 30);

    int FH;
    do {
        FH = 0;
        int Hx, Hy;
        Hx= rand() % (1920 - (int)Hospital->Length);
        Hy = rand() % (1080 - (int)Hospital->Height);
        Hospital->Move((float)Hx, (float)Hy);
        for (int i = 0; i < Garden->Count; i++) {
            if (Garden[i]->Contains(Hospital))FH += 1;
        }
    }while(FH > 0);
    //Store = gcnew Store(0, 0);//actualizar valores
    int FP;
    do {
        FP = 0;
        Player->Move(rand() % (1920 - (int)Player->Length), rand() % (1080 - (int)Player->Height));
        for (int i = 0; i < Garden->Count; i++) {
            if (Garden[i]->Contains(Player))FP += 1;
        }
        if (Hospital->Contains(Player))FP += 1;
    } while (FP > 0);
    
    //crear diagrama de aparicion
}

void GameModel::Map::Draw(RenderTarget& rt){
    for (int i = 0; i < Garden->Count; i++) {
        Garden[i]->Draw(rt);
    }
    Hospital->Draw(rt);
    //Store->Draw(rt);
    Player->Draw(rt);
}
