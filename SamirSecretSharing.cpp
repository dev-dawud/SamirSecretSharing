#pragma warning(disable : 4146)
#pragma warning(disable : 4244)

#include <iostream>
#include <string>
#include <vector>
#include <gmp.h>
#include <random>
#include <gmpxx.h>


mpz_class S = 7;
int n = 5;
int t = 3;

int calcGrade = 0;

class Encrypt {
private:
    mpz_class p;

public:

    // AI-Generated - 2^255 - 19
    Encrypt() {
        p = 1;
        p <<= 255;
        p -= 19;
    }

    void Parameter() {

        std::cout << "For this round, use the following parameters:\n"
            << "S = " << S << "\n"
            << "n = " << n << "\n"
            << "t = " << t << "\n"
            << "p = " << p << "\n"
            << std::endl;
    }

    int calculateGrade() {

        int grade = t - 1;

        std::cout << "Your polynom is a " << grade << " second degree." << std::endl;

        return grade;
    }

    void calculatePolynom() {

        std::cout << std::endl;

        std::random_device rd;

        gmp_randclass generator(gmp_randinit_mt);
        generator.seed(rd());

        int grade = calculateGrade();

        // 'grade' specifies the size of the array 
        // whose coefficients are calculated randomly
        std::vector<mpz_class> arr(grade);

        for(int i = 0; i < arr.size(); i++) {

            arr[i] = generator.get_z_range(p);
        }

        for (int g = 0; g < arr.size(); g++) {

            std::cout << "Your coefficients are " << arr[g] << std::endl;

        }

        std::cout << std::endl;

        // vector for the polynom: S + a1x + a2x^2, ...
        std::vector<mpz_class>polynom = { S };


            for (int j = 0; j < arr.size(); j++) {

                polynom.push_back(arr[j]);

            }

            std::vector<mpz_class> result;


            for (int x = 1; x <= n; x++) {

                mpz_class tmp;
                mpz_class rslt= 0;
           
                for (int i = 0; i < polynom.size(); i++) {

                    mpz_class X = x;

                    mpz_pow_ui(tmp.get_mpz_t(), X.get_mpz_t(), i);

                    rslt += polynom[i] * tmp;

                }

                result.push_back(rslt % p);

            }

            for(int r = 0; r < result.size(); r++){

                std::cout << "P(" << (r + 1) << ", " << result[r] << ")" << std::endl;
            }
       }
};

int main()
{
    Encrypt ec;

    ec.Parameter();
    ec.calculatePolynom();


    return 0;
}