#pragma once

//Déclaration anticipée pour éviter une dépendance cyclique
class CSommet;

class CArc
{
private:
	CSommet * pSMTdest;

public:
	CArc(void);
	~CArc(void);
};

