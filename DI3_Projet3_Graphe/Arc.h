#ifndef ARC_H
#define ARC_H

//D�claration anticip�e pour �viter une d�pendance circulaire
class CSommet;

class CArc
{
private:
	CSommet * pSMTARCdest;

public:
	CArc(CSommet& SMTparam);
	~CArc(void);

	CSommet& ARCgetDest() const;
};

#endif