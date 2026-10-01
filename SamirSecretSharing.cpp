#pragma warning(disable : 4146)
#pragma warning(disable : 4244)

#include <iostream>
#include <string>
#include <vector>
#include <gmp.h>
#include <random>
#include <utility>

int S = 1234;
int n = 6;
int k = 3;
int tmp1 = 1;

class Encrypt {
private:
    mpz_t gmp_S, gmp_n, gmp_k, gmp_r, gmp_tmp1;

public:

    Encrypt() {

        mpz_init_set_ui(gmp_S, S);
        mpz_init_set_ui(gmp_n, n);
        mpz_init_set_ui(gmp_k, k);
        mpz_init_set_ui(gmp_tmp1, tmp1);

        mpz_init(gmp_r);

    }

    std::pair<int, int> calculateCoefficient() {

        mpz_sub(gmp_r, gmp_k, gmp_tmp1);
        mpz_clear(gmp_tmp1);

        int a1 = 0;
        int a2 = 0;

        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> dist(1, 10);

        a1 = dist(generator);
        a2 = dist(generator);



        std::cout << "You will get " << gmp_r << " random a's:" << std::endl;
        std::cout << "a1: " << a1 << std::endl;
        std::cout << "a2: " << a2 << std::endl << std::endl;

            return { a1, a2 };
    }

    void calculatePolynom(int a1, int a2) {

        std::cout << "f(x) = " << S << " + " << a1 << " + " << a2 << std::endl;

    }




    ~Encrypt() {

        mpz_clear(gmp_S);
        mpz_clear(gmp_n);
        mpz_clear(gmp_k);
        mpz_clear(gmp_r);
    }
};

int main()
{
    Encrypt ec;

    auto [a, b] = ec.calculateCoefficient();

    ec.calculatePolynom(a, b);


    return 0;
}