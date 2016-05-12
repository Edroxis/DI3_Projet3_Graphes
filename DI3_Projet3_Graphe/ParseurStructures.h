#ifndef PARSEURSTRUCTURES_H
#define PARSEURSTRUCTURES_H

struct CParseurVariable
{
	char * key;
	char * value;
};

struct CParseurTableau
{
	char * key;
	unsigned int nbVariables;
	CParseurVariable* variables;
};

#endif