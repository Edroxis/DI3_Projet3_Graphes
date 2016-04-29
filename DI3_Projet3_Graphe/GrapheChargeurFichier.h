#include <iostream>
#include <fstream>


#pragma once
class CGrapheChargeurFichier
{
private:
	unsigned int argc;
	char ** cle;
	char ** valeur;

public:
	CGrapheChargeurFichier(void);
	~CGrapheChargeurFichier(void);
	void GCFchargeFichier(char * chemin);
	char * GCFgetValeur(char * valCherche);
	bool GCFequalsString(char * ch1, char * ch2);

private:
	int GCFtrouverCle(char * cleCherchee);
	char * GCFtrouverValeur(int indice);
	void GCFajouterCouple(char * cleParam, char * value);
};

