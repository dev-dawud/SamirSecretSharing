#pragma once

#pragma warning(disable : 4146)
#pragma warning(disable : 4244)

#include <vector>
#include <gmpxx.h>

class Reconstruct {
private:

	mpz_class p;

	std::vector<mpz_class> chosenPoints;

public:

	Reconstruct();
	void getPoints(std::vector<mpz_class> result, int calcGrade);
	void calculateLagrange();

};