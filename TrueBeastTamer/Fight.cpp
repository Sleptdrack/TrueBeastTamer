#include "pch.h"
#include "Fight.h"

void GameController::Fight::Hunt(Map^ M, Arena^ A, RenderWindow& W){
	for (int i = 0; i < M->Garden->Count; i++) {
		bool t = false;
		M->Garden[i]->Spawn(M->Player, &t);
		if (t){
			if (A == nullptr)A = gcnew Arena(M->Garden[i]->LBeast[0]);
			W.setActive(false);
			A->Show(M);
			if (A->B->Health[3] <= 0) {
				M->Garden[i]->LBeast->RemoveAt(0);
			}
		}

	}
}
