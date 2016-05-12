#include "MyString.h"
#include <string.h>

void CMyString::MSTsuppEspace(char * const pcchaine)
{
	char* pcFirstIndex = pcchaine;
	char* pcSecIndex = pcchaine;

	while(*pcSecIndex != 0)
	{
		*pcFirstIndex = *pcSecIndex++;
		if(*pcFirstIndex != ' ')
			pcFirstIndex++;
	}

	*pcFirstIndex = '\0';
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
