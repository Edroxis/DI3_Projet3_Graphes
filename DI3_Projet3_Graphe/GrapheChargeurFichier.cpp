#include "GrapheChargeurFichier.h"
#include <stdlib.h>
#include <cstdio>

using namespace std;

CGrapheChargeurFichier::CGrapheChargeurFichier(void)
{
	uiGCFargc = 0;
	ppcGCFcle = (char **) malloc(0 * sizeof(char*));
	ppcGCFvaleur = (char **) malloc(0 * sizeof(char*));
}


CGrapheChargeurFichier::~CGrapheChargeurFichier(void)
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

void CGrapheChargeurFichier::GCFchargeFichier(char * chemin)
{
	//Lecture de tout le fichier
	//Si =, stocker partie gauche dans key, partie droite dans value au même indice
	char * cpline = new char[64];
	int iindexEqual;

	ifstream fichier(chemin, ios::in);  // on ouvre le fichier en lecture

	if(fichier)  // si l'ouverture a réussi
	{
	    while(!fichier.eof())
	    {
	        fichier.getline(cpline,64);
            //cout << cpline << "\n";
            iindexEqual = GCFfindChar(cpline, '=');
            if(iindexEqual != -1)
                cpline[iindexEqual] = 0;
            GCFajouterCouple(cpline, cpline+iindexEqual+1);
            //TODO gérer cas ou virgule dans la ligne
	    }
	    delete cpline;
    }
	else
		cerr << "Impossible d'ouvrir le fichier " << chemin << " !" << endl;
}

/*int CGrapheChargeurFichier::GCFtrouverCle(char * cleCherchee)
{
	//Chercher valeur en param dans le tableau cle
	//Renvoyer indice si trouvé
	//sinon renvoyer -1
}

char * CGrapheChargeurFichier::GCFtrouverValeur(int indice)
{
	//Renvoyer la valeur correspondante a la cle du tableau valeur
}*/

void CGrapheChargeurFichier::GCFafficherTabs()
{
    unsigned int uiboucle;
    for(uiboucle = 0; uiboucle < uiGCFargc; uiboucle++)
    {
        cout << ppcGCFcle[uiboucle] << " : " << ppcGCFvaleur[uiboucle] << endl;
    }
}

void CGrapheChargeurFichier::GCFajouterCouple(char * cleParam, char * valeurParam)
{
	uiGCFargc++;

	//Ajouter cle au tableau cle
		//réallouer cle par realloc
    ppcGCFcle = (char **) realloc(ppcGCFcle, uiGCFargc * sizeof(char*));
		//cle alloué par new
    ppcGCFcle[uiGCFargc-1] = GCFstrDup(cleParam);

	//Ajouter valeur au tableau valeur
        //réallouer valeur par realloc
    ppcGCFvaleur = (char **) realloc(ppcGCFvaleur, uiGCFargc * sizeof(char*));
		//valeur alloué par new
    ppcGCFvaleur[uiGCFargc-1] = GCFstrDup(valeurParam);
}

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

int CGrapheChargeurFichier::GCFfindChar(char * ch1, char c)
{
    int iboucle = 0;
    while(*ch1 != 0)
    {
        if(*ch1 == c)
            return iboucle;
        iboucle++;
        ch1++;
    }
    return -1;
}

int CGrapheChargeurFichier::GCFstrLength(char * ch1)
{
    int iboucle = 0;
    while(*ch1 != 0)
    {
        iboucle++;
        ch1++;
    }
    return iboucle;
}

char * CGrapheChargeurFichier::GCFstrDup(char * ch1)
{
    int istrSize = GCFstrLength(ch1);
    char * cpres = new char[istrSize];
    while(*ch1 != 0)
    {
        *cpres = *ch1;
        cpres++;
        ch1++;
    }
    cpres -= istrSize;
    return cpres;
}


