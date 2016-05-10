#include "Arc.h"


CArc::CArc(CSommet& SMTparam)
{
    pSMTARCdest = &SMTparam;
}


CArc::~CArc()
{
}

CSommet& CArc::ARCgetDest() const
{
    return *pSMTARCdest;
}
