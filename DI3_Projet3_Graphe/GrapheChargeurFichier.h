#include <iostream>
#include <fstream>


#pragma once
class CGrapheChargeurFichier
{
private:
	unsigned int uiGCFargc;
	char ** ppcGCFcle;
	char ** ppcGCFvaleur;

public:
	CGrapheChargeurFichier(void);
	~CGrapheChargeurFichier(void);
	void GCFchargeFichier(char * chemin);
	int GCFtrouverCle(char * cleCherchee);
	char * GCFtrouverValeur(int indice);
	void GCFafficherTabs();
	bool GCFequalsString(char * ch1, char * ch2);
    int GCFfindChar(char * ch1, char c);
    int GCFstrLength(char * ch1);
    char * GCFstrDup(char * ch1);

private:
	void GCFajouterCouple(char * cleParam, char * value);
};

