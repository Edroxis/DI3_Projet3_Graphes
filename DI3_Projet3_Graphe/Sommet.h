#pragma once

#include "Arc.h"

class CSommet
{
private:
	unsigned int uinumero;
	unsigned int uitotal;
	unsigned int uinbArrivant;
	unsigned int uinbPartant;
	CArc ** ppARCarrivant;
	CArc ** ppARCpartant;

public:
	CSommet(void);
	~CSommet(void);
};

