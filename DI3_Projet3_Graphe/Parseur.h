#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "ObjetRemplisseur.h"

//TODO: Vérifier valeurs exceptions
#define EXCEPTION_UNABLE_TO_OPEN_FILE 4 
#define EXCEPTION_UNABLE_TO_PARSE_FILE 5

class CParseur
{
public:
	/* CParseur ne garde pas de copie du CObjectRemplisseur,
	donc veillez à sa conservation en mémoire pour parse() */
	CParseur(CObjetRemplisseur* remplisseur);

	void PRSparse(const char* emplacement, void* objetARemplir);

private:
	void PRSparseLine(char* line);
	void PRSparseArray(char* line, int equalPos);
	void PRSparseVariable(char* line, int equalPos);

private:
	CObjetRemplisseur* remplisseur;
	bool tableauEnParsement;
};

#endif