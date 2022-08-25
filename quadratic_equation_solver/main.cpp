#include "quadr_solver.h"

int main(void)
{
    if (DO_TESTS) start_tests();

    double a = NAN, b = NAN, c = NAN;

    get_coeffs(&a, &b, &c);

    double x1 = NAN, x2 = NAN;
    int roots_amount = solve_quadr(a, b, c, &x1, &x2);

    switch (roots_amount)
    {
        case TWO_ROOTS:
            printf("%.4f; %.4f", min_of_two(x1, x2), max_of_two(x1, x2));
            break;
        case ONE_ROOT:
            printf("%.4f", x1);
            break;
        case NO_ROOTS:
            printf("No real solutions.");
            break;
        case INF_ROOTS:
            printf("x can be any real number.");
            break;
        default:
            printf("Incorrect solutions amount");
    }

    getchar();

    return 0;
}
