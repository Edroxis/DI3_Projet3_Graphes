#include "GrapheChargeurFichier.h"
#include <stdlib.h>
#include <cstdio>
#include "MyString.h"

using namespace std;

CGrapheChargeurFichier::CGrapheChargeurFichier()
{
	uiGCFargc = 0;
	ppcGCFcle = (char **) malloc(0 * sizeof(char*));
	ppcGCFvaleur = (char **) malloc(0 * sizeof(char*));
}


CGrapheChargeurFichier::~CGrapheChargeurFichier()
{
	unsigned int iboucle;
	for(iboucle = 0; iboucle < uiGCFargc; iboucle++)
	{
		delete ppcGCFcle[iboucle];
		delete ppcGCFvaleur[iboucle];
	}
	free(ppcGCFcle);
	free(ppcGCFvaleur);
}

void CGrapheChargeurFichier::GCFchargeFichier(char const * const chemin)
{
	//Lecture de tout le fichier
	//Si =, stocker partie gauche dans key, partie droite dans value au même indice
	char pcligne[64];

	ifstream fichier(chemin, ios::in);  // on ouvre le fichier en lecture

	if(fichier)  // si l'ouverture a réussi
	{
	    while(!fichier.eof())
	    {
	        fichier.getline(pcligne,64);
	        CMyString::MSTsuppEspace(pcligne);
	        GCFseparerMembres(pcligne);
        }
    }
	else
		cerr << "Impossible d'ouvrir le fichier " << chemin << " !" << endl;
}

unsigned int CGrapheChargeurFichier::GCFtrouverCle(char const * const pccleCherchee, unsigned int uiindexMin)
{
	//Chercher valeur en param dans le tableau cle
	//Renvoyer indice si trouvé
	//sinon renvoyer -1
	unsigned int uiboucle;
	for(uiboucle = uiindexMin; uiboucle < uiGCFargc; uiboucle++)
        if(strcmp(ppcGCFcle[uiboucle], pccleCherchee) == 0)
           return uiboucle;
    return -1;
}

char const * const CGrapheChargeurFichier::GCFtrouverValeur(unsigned int uiindice)
{
	//Renvoyer la valeur correspondante a la cle du tableau valeur
	return ppcGCFvaleur[uiindice];
}

void CGrapheChargeurFichier::GCFafficherTabs()
{
    unsigned int uiboucle;
    for(uiboucle = 0; uiboucle < uiGCFargc; uiboucle++)
    {
        cout << ppcGCFcle[uiboucle] << " : " << ppcGCFvaleur[uiboucle] << endl;
    }
}

void CGrapheChargeurFichier::GCFajouterCouple(char const * const cleParam, char const * const valeurParam)
{
	uiGCFargc++;

	//Ajouter cle au tableau cle
		//réallouer cle par realloc
    ppcGCFcle = (char **) realloc(ppcGCFcle, uiGCFargc * sizeof(char*));
		//cle alloué par new
    ppcGCFcle[uiGCFargc-1] = _strdup(cleParam);

	//Ajouter valeur au tableau valeur
        //réallouer valeur par realloc
    ppcGCFvaleur = (char **) realloc(ppcGCFvaleur, uiGCFargc * sizeof(char*));
		//valeur alloué par new
    ppcGCFvaleur[uiGCFargc-1] = _strdup(valeurParam);
}

void CGrapheChargeurFichier::GCFseparerMembres(char * const chaine)
{
    int iindexEgal, iindexVirgule;
	iindexVirgule = CMyString::MSTtrouverChar(chaine, ',');

    if(iindexVirgule != -1)
    {
        chaine[iindexVirgule] = 0;
        GCFseparerMembres(chaine);
        GCFseparerMembres(chaine + iindexVirgule + 1);
        return;
    }

	iindexEgal = CMyString::MSTtrouverChar(chaine, '=');
    chaine[iindexEgal] = 0;
    GCFajouterCouple(chaine, chaine+iindexEgal+1);
}