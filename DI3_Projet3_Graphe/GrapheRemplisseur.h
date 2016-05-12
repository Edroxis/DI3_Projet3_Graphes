#ifndef CGRAPHEREMPLISSEUR_H
#define CGRAPHEREMPLISSEUR_H

#include "ObjetRemplisseur.h"
#include "ParseurStructures.h"

//D�claration anticip�e pour �viter l'inclusion circulaire
class CGraphe;

class CGrapheRemplisseur: public CObjetRemplisseur
{
public:
	~CGrapheRemplisseur();
	void registerObject2Modify(void* obj);
	void handleVariable(const CParseurVariable& var);
	void handleArray(const CParseurTableau& arr);

private:
	CGraphe* graphe;
};

#endif