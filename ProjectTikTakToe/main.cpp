#include "JeuSDL.h"
#include "src/Joueur/Joueur.h"
#include "src/Gris_du_jeu/Gris_du_jeu.h"
#include "src/Image/Image.h"

using namespace std;

void test_regression() {
	/*bool monbool;
	string nom;
	Joueur J1;
	Gris_du_jeu monGris;
	monGris.affichage();
	monbool = monGris.YatilDesCasesLibres();
	cout << monbool<<"\n";
	cout << "Quelle est votrre nom\n";
	cin >> nom;
	J1.setNom(nom);
	cout << J1.getChoix() << " " <<J1.getNomJoueur()<<"\n";
	monGris.~Gris_du_jeu();*/	
	JeuSDL Jeu;
	int i = 0;
	Jeu.init("Jeu de Tik Tak Toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, false);
	Image img;
	//img.loadFromFile("Grille.png", Jeu.getRenderer());
	//img.draw(Jeu.getRenderer(), nullptr, nullptr, 400);
	while (Jeu.running()) {
		Jeu.handlevent();
		//img.loadFromFile("Grille.png", Jeu.getRenderer());
		Jeu.render();
		cout << i++ << " ";
	}
	Jeu.clean();

	/*while (Jeu.running()) {
		Jeu.handlevent();
		img.loadFromFile("data/Grille.png", Jeu.getRenderer());
		Jeu.update();
		Jeu.render();
	}
	Jeu.clean();*/
}

//JeuSDL *Jeu = nullptr;

int main(int argc, char *argv[]) {
	test_regression();
	
	
	return 0;
}