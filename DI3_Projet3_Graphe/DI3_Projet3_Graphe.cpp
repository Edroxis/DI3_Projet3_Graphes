#include <iostream>
#include "GrapheChargeurFichier.h"

using namespace std;

int main(int argc, char* argv[])
{
	int e;
	CGrapheChargeurFichier test;
	char * testStr = "test";
	/*char * test1 = "test";
	char * test2 = "test";
	cout << test.GCFequalsString(test1, test2);
	cout << test1;*/

    test.GCFchargeFichier("graphe1.txt");

    /*testStr = test.GCFstrDup(testStr);
    cout << testStr;

    delete testStr;*/

    test.GCFafficherTabs();

	scanf("%d",&e);
	return 0;
}

