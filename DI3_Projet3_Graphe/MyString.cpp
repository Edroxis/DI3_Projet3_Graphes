#include "MyString.h"
#include <string.h>

void CMyString::MSTsuppEspace(char * const pcchaine)
{
    int espaceCount = 0, iboucle = 0;
    char * pctemp;
    while(pcchaine[iboucle] != 0)
    {
        pctemp = pcchaine;
        while(*pctemp == ' ')
        {
            espaceCount++;
            pctemp++;
        }
        pcchaine[iboucle] = pcchaine[iboucle + espaceCount];
        iboucle++;
        if(pcchaine[iboucle] == 0)
            break;
    }
}

int CMyString::MSTtrouverChar(char const * const ch1, char const c)
{
    int iboucle = 0;
    while(ch1[iboucle] != 0)
    {
        if(ch1[iboucle] == c)
            return iboucle;
        iboucle++;
    }
    return -1;
}
