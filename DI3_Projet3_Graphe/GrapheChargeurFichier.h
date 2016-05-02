#ifndef GRAPHE_CHARGEUR_FICHIER_H
#define GRAPHE_CHARGEUR_FICHIER_H

#include <iostream>
#include <fstream>

class CGrapheChargeurFichier
{
private:
	unsigned int uiGCFargc;
	char ** ppcGCFcle;
	char ** ppcGCFvaleur;

public:
	CGrapheChargeurFichier();
	~CGrapheChargeurFichier();
	void GCFchargeFichier(char const * const pcchemin);
	unsigned int GCFtrouverCle(char * pccleCherchee, unsigned int uiindexMin=0);
	char * GCFtrouverValeur(unsigned int uiindice);
	void GCFafficherTabs();

private:
	void GCFajouterCouple(char * pccleParam, char * pcvalue);
	void GCFseparerMembres(char * pcchaine);
};

#endif