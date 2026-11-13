#pragma once

#pragma warning(disable : 4146)
#pragma warning(disable : 4244)

#include <vector>
#include <gmpxx.h>

class Generate {
private:

	mpz_class p;
	mpz_class S = 7;
	int n = 5;
	int t = 3;

	int calcGrade = 0;
	std::vector<mpz_class> result;
	

public:

	Generate();
	void Parameter();
	int calculateGrade();
	void calculatePolynom();
	std::vector<mpz_class> getResult();
	int getCalcGrade();


};