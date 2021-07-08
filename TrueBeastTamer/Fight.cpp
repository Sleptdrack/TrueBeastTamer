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
			//if (A->B->Health[3] <= 0) {
		    M->Garden[i]->LBeast->RemoveAt(0);
			//}
		}

	}
}

void GameController::Fight::Battle(Beast^ B, Tamer^ T,int* c){
	if (T->Bag->Beast[*c]->Power[0]->InUse) {
		if (T->Bag->Beast[*c]->Power[0]->Shot->Count > 0) {
			if (T->Bag->Beast[*c]->Power[0]->Shot[0]->Contains(B)) {
				std::cout << B->Health[3] << "\n";
				if (T->Bag->Beast[*c]->Attack[3] - B->Defense[3] <= 0) {
					B->Health[3] -= 1;
					T->Bag->Beast[*c]->Exp += 5;
				}
				else {
					B->Health[3] -= T->Bag->Beast[*c]->Attack[3] - B->Defense[3];//el tercer elemento es el valor real que posee
				}
				//agregar metodo para definir daño por elemento
				T->Bag->Beast[*c]->Power[0]->Move->stop();
				T->Bag->Beast[*c]->Power[0]->Hit->play();
				T->Bag->Beast[*c]->Power[0]->Shot->Clear();

			}
		}
		*T->Bag->Beast[*c]->Power[0]->time = T->Bag->Beast[*c]->Power[0]->clk->getElapsedTime();
		if (T->Bag->Beast[*c]->Power[0]->time->asMilliseconds() > T->Bag->Beast[*c]->Power[0]->cooldown * (1 - T->Bag->Beast[*c]->Cooldown[3] * .01)) {
			T->Bag->Beast[*c]->Power[0]->InUse = false;
			T->Bag->Beast[*c]->Power[0]->clk->restart();
		}

	}
	if (B->Health[3] <= 0) {
		//reemplazar por metodo para atrapar o liberar Beast
		T->Bag->Beast[*c]->Exp += 20;
		B->Health[3] = 0;
	}
	
	if (B->Power[0]->InUse) {
		if (B->Power[0]->Shot->Count > 0) {
			if (B->Power[0]->Shot[0]->Contains(T->Bag->Beast[*c])) {
				if (B->Attack[3] - T->Bag->Beast[*c]->Defense[3] <= 0) {
					T->Bag->Beast[*c]->Health[3] -= 1;
					B->Exp += 5;
				}
				else {
					T->Bag->Beast[*c]->Health[3] -= B->Attack[3] - T->Bag->Beast[*c]->Defense[3];//el tercer elemento es el valor real que posee
				}
				//agregar metodo para definir daño por elemento
				B->Power[0]->Move->stop();
				B->Power[0]->Hit->play();
				B->Power[0]->Shot->Clear();
			}
		}
		*B->Power[0]->time = B->Power[0]->clk->getElapsedTime();
		if (B->Power[0]->time->asMilliseconds() > B->Power[0]->cooldown * (1 - B->Cooldown[3] * .01)) {
			B->Power[0]->InUse = false;
			B->Power[0]->clk->restart();
		}

	}
	if (T->Bag->Beast[*c]->Health[3] <= 0) {
		//AGREGAR CAMBIO DE BEAST O PERDIDA
		B->Exp += 20;
		T->Bag->Beast[*c]->Health[3] = 0;
		if (T->Bag->Beast->Count > *c + 2) {
			T->Bag->Beast[*c + 1]->X = T->Bag->Beast[*c]->X;
			T->Bag->Beast[*c + 1]->Y = T->Bag->Beast[*c]->Y;
			*c += 1;
		}
		else {
			T->Bag->Beast[0]->X = T->Bag->Beast[*c]->X;
			T->Bag->Beast[0]->Y = T->Bag->Beast[*c]->Y;
			*c = 0;
		}

	}
}
