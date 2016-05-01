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
	char * pcligne = new char[64];

	ifstream fichier(chemin, ios::in);  // on ouvre le fichier en lecture

	if(fichier)  // si l'ouverture a réussi
	{
	    while(!fichier.eof())
	    {
	        fichier.getline(pcligne,64);
	        GCFsuppEspace(pcligne);
	        GCFseparerMembres(pcligne);
        }
	    delete pcligne;
    }
	else
		cerr << "Impossible d'ouvrir le fichier " << chemin << " !" << endl;
}

unsigned int CGrapheChargeurFichier::GCFtrouverCle(char * pccleCherchee, unsigned int uiindexMin)
{
	//Chercher valeur en param dans le tableau cle
	//Renvoyer indice si trouvé
	//sinon renvoyer -1
	unsigned int uiboucle;
	for(uiboucle = uiindexMin; uiboucle < uiGCFargc; uiboucle++)
        if(GCFequalsString(ppcGCFcle[uiboucle], pccleCherchee))
           return uiboucle;
    return -1;
}

char * CGrapheChargeurFichier::GCFtrouverValeur(unsigned int uiindice)
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

int CGrapheChargeurFichier::GCFtrouverChar(char * ch1, char c)
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

int CGrapheChargeurFichier::GCFlongeurChaine(char * ch1)
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
    int istrSize = GCFlongeurChaine(ch1);
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

void CGrapheChargeurFichier::GCFseparerMembres(char * chaine)
{
    int iindexEgal, iindexVirgule;
    iindexVirgule = GCFtrouverChar(chaine, ',');

    if(iindexVirgule != -1)
    {
        chaine[iindexVirgule] = 0;
        GCFseparerMembres(chaine);
        GCFseparerMembres(chaine + iindexVirgule + 1);
        return;
    }

    iindexEgal = GCFtrouverChar(chaine, '=');
    chaine[iindexEgal] = 0;
    GCFajouterCouple(chaine, chaine+iindexEgal+1);
}

void CGrapheChargeurFichier::GCFsuppEspace(char * pcchaine)
{
    int espaceCount = 0;
    char * pctemp;
    while(*pcchaine != 0)
    {
        pctemp = pcchaine;
        while(*pctemp == ' ')
        {
            espaceCount++;
            pctemp++;
        }
        *pcchaine = *(pcchaine+espaceCount);
        pcchaine++;
        if(*pcchaine == 0)
            break;
    }
}
