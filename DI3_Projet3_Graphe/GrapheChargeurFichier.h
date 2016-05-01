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
	void GCFchargeFichier(char * pcchemin);
	unsigned int GCFtrouverCle(char * pccleCherchee, unsigned int uiindexMin=0);
	char * GCFtrouverValeur(unsigned int uiindice);
	void GCFafficherTabs();
	bool GCFequalsString(char * pcchaine1, char * pcchaine2);
    int GCFtrouverChar(char * pcchaine, char c);
    int GCFlongeurChaine(char * pcchaine);
    char * GCFstrDup(char * pcchaine);
    void GCFsuppEspace(char * pcchaine);

private:
	void GCFajouterCouple(char * pccleParam, char * pcvalue);
	void GCFseparerMembres(char * pcchaine);
};

