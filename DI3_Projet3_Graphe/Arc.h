#pragma once

//D�claration anticip�e pour �viter une d�pendance cyclique
class CSommet;

class CArc
{
private:
	CSommet * pSMTdest;

public:
	CArc(void);
	~CArc(void);
};

