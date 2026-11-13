#include "../header/reconstruct.h"

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <gmpxx.h>

    
Reconstruct :: Reconstruct() {

        p = 1;
        p <<= 255;
        p -= 19;

    }
    void Reconstruct :: getPoints(std::vector<mpz_class> result, int calcGrade) {


        for (int i = 0; i < calcGrade + 1; i++) {

            chosenPoints.push_back(result[i]);
        }


        std::cout << "\nPoints for reconstruction:" << std::endl;


        for (int r = 0; r < chosenPoints.size(); r++) {

            std::cout << "P(" << (r + 1) << ", " << chosenPoints[r] << ")" << std::endl;
        }
    }


    void Reconstruct :: calculateLagrange() {

        mpz_class secret = 0;


        for (int i = 0; i < chosenPoints.size(); i++) {

            mpz_class zaehler = 1;
            mpz_class nenner = 1;
            mpz_class xi = i + 1;


            for (int j = 0; j < chosenPoints.size(); j++) {

                if (i != j) {

                    mpz_class xj = j + 1;

                    zaehler *= (0 - xj);
                    nenner *= (xi - xj);
                }
            }

            // AI Generated
            nenner %= p;

            if (nenner < 0) {

                nenner += p;
            }

            // AI Generated
            mpz_class invNenner;
            mpz_invert(invNenner.get_mpz_t(), nenner.get_mpz_t(), p.get_mpz_t());

            // AI Generated
            mpz_class tmp = chosenPoints[i] * zaehler * invNenner;
            secret += tmp;
            secret %= p;
        }


        std::cout << "\nReconstructed Secret S = " << secret << std::endl;
    }