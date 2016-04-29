#include "GrapheChargeurFichier.h"
#include <stdlib.h>

using namespace std;

CGrapheChargeurFichier::CGrapheChargeurFichier(void)
{
	argc = 0;
	cle = (char **) malloc(0 * sizeof(char*));
	valeur = (char **) malloc(0 * sizeof(char*));
}


CGrapheChargeurFichier::~CGrapheChargeurFichier(void)
{
	unsigned int iboucle;
	for(iboucle = 0; iboucle < argc; iboucle++)
	{
		delete cle[iboucle];
		delete valeur[iboucle];
	}
	free(cle);
	free(valeur);
}

/*void CGrapheChargeurFichier::GCFchargeFichier(char * chemin)
{
	//Lecture de tout le fichier
	//Si =, stocker partie gauche dans key, partie droite dans value au même indice
	ifstream fichier(chemin, ios::in);  // on ouvre le fichier en lecture

	if(fichier)  // si l'ouverture a réussi
	{
	
	}
	else
		cerr << "Impossible d'ouvrir le fichier " << chemin << " !" << endl;
}*/

/*char * CGrapheChargeurFichier::GCFgetValeur(char * valCherche)
{
	//Chercher si valeur en param est dans le tableau des clés
		//Si oui, chercher la valeur correspondante
			//Renvoyer valeur correspondante
		//Si non renvoyer erreur
}

int CGrapheChargeurFichier::GCFtrouverCle(char * cleCherchee)
{
	//Chercher valeur en param dans le tableau cle
	//Renvoyer indice si trouvé
	//sinon renvoyer -1
}

char * CGrapheChargeurFichier::GCFtrouverValeur(int indice)
{
	//Renvoyer la valeur correspondante a la cle du tableau valeur
}

void CGrapheChargeurFichier::GCFajouterCouple(char * cleParam, char * valeurParam)
{
	argc++;

	//Ajouter cle au tableau cle
		//réallouer cle par realloc
		//cle alloué par new

	//Ajouter valeur au tableau valeur
		//réallouer valeur par realloc
		//valeur alloué par new
}*/

bool CGrapheChargeurFichier::GCFequalsString(char * ch1, char * ch2)
{
	//Teste égalité de 2 chaines
	while(*ch1 != 0 && *ch2 != 0)
	{
		if(*ch1 != *ch2)
			return false;
		ch1++;
		ch2++;
	}
	if(*ch1 != 0 || *ch2!=0)
		return false;
	return true;
}