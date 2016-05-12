#ifndef COBJETREMPLISSEUR_H
#define COBJETREMPLISSEUR_H

#include "ParseurStructures.h"

class CObjetRemplisseur
{
public:
	virtual ~CObjetRemplisseur() {};
	virtual void registerObject2Modify(void* obj) = 0;
	virtual void handleVariable(const CParseurVariable& var) = 0;
	virtual void handleArray(const CParseurTableau& arr) = 0;
};

#endif