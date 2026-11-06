#pragma warning(disable : 4146)
#pragma warning(disable : 4244)

#include <iostream>
#include <string>
#include <vector>
#include <gmp.h>
#include <random>
#include <utility>
#include <gmpxx.h>

int S = 7;
int n = 5;
int t = 3;
int p = 19;

int calcGrade = 0;

class Encrypt {
private:

    mpz_t gmp_S, gmp_n, gmp_t, gmp_p, gmp_r, gmp_calcGrade;

public:

    Encrypt() {

        mpz_init_set_ui(gmp_S, S);
        mpz_init_set_ui(gmp_n, n);
        mpz_init_set_ui(gmp_t, t);
        mpz_init_set_ui(gmp_p, p);
        mpz_init_set_ui(gmp_calcGrade, calcGrade);

        mpz_init(gmp_r);

    }

    void Parameter() {

        std::cout << "For this round, use the following parameters: \n"
            << S << " \n"
            << n << " \n"
            << t << " \n"
            << p << " \n"
            << std::endl;
    }

    double calculateGrade() {

        double grade = t - 1;

        std::cout << "Your polynom is a " << grade << " second degree." << std::endl;

        return grade;
    }

    void calculatePolynom() {

        std::cout << std::endl;

        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> dist(1, 10);

        double grade = calculateGrade();

        // 'grade' specifies the size of the array 
        // whose coefficients are calculated randomly
        std::vector<int> arr(grade);

        for(int i = 0; i < arr.size(); i++) {

            arr[i] = dist(generator);
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

                double tmp;
                mpz_class rslt= 0;
                double xPow = 0;
           
                for (int i = 0; i < polynom.size(); i++) {

                    tmp = std::pow(x, xPow);

                    rslt += polynom[i] * tmp;


                    xPow += 1;

                }

                result.push_back(rslt % p);

                xPow = 0;
            }

            for(int r = 0; r < result.size(); r++){

                std::cout << "P(" << (r + 1) << ", " << result[r] << ")" << std::endl;
            }
       }



    ~Encrypt() {

        mpz_clear(gmp_S);
        mpz_clear(gmp_n);
        mpz_clear(gmp_t);
        mpz_clear(gmp_r);
    }
};

int main()
{
    Encrypt ec;

    ec.Parameter();
    ec.calculatePolynom();


    return 0;
}