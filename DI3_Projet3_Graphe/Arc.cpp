#include "Arc.h"


CArc::CArc(CSommet& SMTparam)
{
    pSMTARCdest = &SMTparam;
}


CArc::~CArc(void)
{
}

CSommet& CArc::ARCgetDest(){
    return *pSMTARCdest;
}
