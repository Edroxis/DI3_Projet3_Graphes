#ifndef UNITTEST_H
#define UNITTEST_H

class CUnitTest
{
public:
	CUnitTest();
	void run();

private:
	void test_GPH_getTotalSommet();
	void test_GPH_getSommet();
	void test_GPH_existantSommet();
	void test_GPH_ajouterSommet();
	void test_GPH_supprimerSommet();
};

#endif