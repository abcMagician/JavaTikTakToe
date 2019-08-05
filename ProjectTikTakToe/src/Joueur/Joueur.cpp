#include "Joueur.h"

Joueur::Joueur(){
	NomJoueur = "Inconnue";
	PointDuJoueur = 0;
	choix = choisirXouO();
}

/*Joueur::~Joueur(){
	NomJoueur = "";
	PointDuJoueur = 0;
}*/

void Joueur::setNom(const string & NouveauNom){
	NomJoueur = NouveauNom;
}

void Joueur::setPoints(const int & Points){
	PointDuJoueur = Points;
}

unsigned int Joueur::getPointDuJoueur()const{
	return PointDuJoueur;
}

string Joueur::getNomJoueur()const{
	return NomJoueur;
}

char Joueur::getChoix()const {
	return choix;
}

/*void Joueur::poserUnXouUnO(){
	
}*/

char Joueur::choisirXouO(){
	char entrerClavier;
	std::cout<< "Choisr X ou O\n";
	std::cin >> entrerClavier;
	while (entrerClavier != 'X' && entrerClavier != 'O') {
		std::cout << "Sasis invalide choisissez X ou O\n";
		std::cin >> entrerClavier;
	}
	return entrerClavier;
}