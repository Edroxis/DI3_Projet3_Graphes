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

	void test_SMT_getNumero();
	void test_SMT_getPartant();
	void test_SMT_getArrivant();
	void test_SMT_ajouterArc();
	void test_SMT_supprimerArc();
	void test_SMT_getArc();
	void test_SMT_getNbArrivant();
	void test_SMT_getNbPartant();

	void test_ARC();
};

#endif