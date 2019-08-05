#ifndef GRIS_DU_JEU_H
#define GRIS_DU_JEU_H
#include <iostream>

using namespace std;

class Gris_du_jeu{
private:
	char GrisDuJeu[3][3];
        
public:
        Gris_du_jeu();
		~Gris_du_jeu();
		void caseMisAjours();
        bool CaseExisteDeja()const;
        bool CaseEstVide(const char &cetteCase)const;
        bool YatilDesCasesLibres()const;
        void affichage()const;
};
#endif
