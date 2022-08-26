#include "quadr_solver.h"

int main(int argc, char *argv[])
{
    if (argc == 2 && !strcmp("do_tests", argv[1]))
    {
        start_tests();

        getchar();

        return 0;
    }

    double a = NAN, b = NAN, c = NAN;

    get_coeffs(&a, &b, &c);

    double x1 = NAN, x2 = NAN;
    int roots_amount = solve_quadr(a, b, c, &x1, &x2);

    print_roots(roots_amount, &x1, &x2);

    getchar();

    return 0;
}

