#include "pch.h"
#include "Map.h"

GameModel::Map::Map(int ng, int nn){
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
    //Hospital = gcnew Hospital(0, 0);//actualizar valores despues
    //Store = gcnew Store(0, 0);//actualizar valores
    //Player = gcnew Tamer(200, 200);//actualizar valores
    //crear diagrama de aparicion
}

void GameModel::Map::Draw(RenderTarget& rt){
    for (int i = 0; i < Garden->Count; i++) {
        Garden[i]->Draw(rt);
    }
    //Hospital->Draw(rt);
    //Store->Draw(rt);
    //Player->Draw(rt);
}
