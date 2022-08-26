#include "quadr_solver.h"

int main(int argc, char *argv[])
{
    char default_test_data_filename[17] = "test_eq_data.txt";

    if (argc == 2 && !strcmp("do_tests", argv[1]))
    {
        start_tests(default_test_data_filename);

        getchar();

        return 0;
    }

    if (argc == 3 && !strcmp("do_tests", argv[1]))
    {
        start_tests(argv[2]);

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

