#ifndef GRAPHE_CHARGEUR_FICHIER_H
#define GRAPHE_CHARGEUR_FICHIER_H

#include <iostream>
#include <fstream>

//TODO: Renommer en CParserFichier

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
	unsigned int GCFtrouverCle(char const * const pccleCherchee, unsigned int uiindexMin=0);
	char const * const GCFtrouverValeur(unsigned int uiindice);
	void GCFafficherTabs();

private:
	void GCFajouterCouple(char const * const pccleParam, char const * const pcvalue);
	void GCFseparerMembres(char * const pcchaine);
};

#endif