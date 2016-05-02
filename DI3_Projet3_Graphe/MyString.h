#ifndef MYSTRING_H
#define MYSTRING_H

//Classe qui fournit des opérations spéciales nous permettant de manipuler des strings
class CMyString
{
public:
    static void MSTsuppEspace(char * const pcchaine);
    static int MSTtrouverChar(char const * const ch1, char const c);
};

#endif