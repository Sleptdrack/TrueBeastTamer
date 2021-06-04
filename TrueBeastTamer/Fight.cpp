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

void GameController::Fight::Battle(Beast^ B, Tamer^ T){
	if (T->Bag->Beast[0]->Power[0]->InUse) {
		if (T->Bag->Beast[0]->Power[0]->Shot[0]->Contains(B)) {
			std::cout << B->Health[3] << "\n";
			B->Health[3] -= T->Bag->Beast[0]->Attack[3] - B->Defense[3];//el tercer elemento es el valor real que posee
			//agregar metodo para definir daño por elemento
			T->Bag->Beast[0]->Power[0]->Move->stop();
			T->Bag->Beast[0]->Power[0]->Hit->play();
			T->Bag->Beast[0]->Power[0]->Shot->Clear();
			T->Bag->Beast[0]->Power[0]->InUse = false;
		}
	}
	if (B->Health[3] <= 0) {
		//reemplazar por metodo para atrapar o liberar Beast
	}
}
