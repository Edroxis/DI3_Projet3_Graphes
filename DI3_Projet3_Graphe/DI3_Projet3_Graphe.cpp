#include <iostream>
#include "GrapheChargeurFichier.h"
#include "Graphe.h"

using namespace std;

int main(int argc, char* argv[])
{
	CGrapheChargeurFichier test;
	test.GCFchargeFichier("graphe1.txt");
	test.GCFafficherTabs();

	int e;
	scanf_s("%d",&e);
	return 0;
}

