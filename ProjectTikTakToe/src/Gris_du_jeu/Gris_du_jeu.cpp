#include "Gris_du_jeu.h"

Gris_du_jeu::Gris_du_jeu(){
        for(unsigned int i = 0; i<3; i++){
			for(unsigned int j = 0; j<3; j++)GrisDuJeu[i][j]= ' ';
        }
}

Gris_du_jeu::~Gris_du_jeu() {
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int j = 0; j < 3; j++)GrisDuJeu[i][j] = ' ';
	}
}

void Gris_du_jeu::caseMisAjours(){

}

/*bool Gris_du_jeu::CaseExisteDeja()const{
	
}*/

bool Gris_du_jeu::CaseEstVide(const char &cetteCase)const{
        return cetteCase == ' ';
}

bool Gris_du_jeu::YatilDesCasesLibres()const{
        for(unsigned int i = 0 ; i<3; i++){
                for(unsigned int j = 0; j<3; j++) return GrisDuJeu[i][j]==' ';
        }
}

void Gris_du_jeu::affichage()const{
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned j = 0; j < 3; j++) std::cout << GrisDuJeu[i][j]<<" ";
		std::cout << "\n";
	}
}