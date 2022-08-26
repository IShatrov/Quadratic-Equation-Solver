#include "quadr_solver.h"

void getnum(double *num)
{
    assert(num != NULL);

    scanf("%lf", num);
    int c = getchar();

    while (c != '\n' || !isfinite(*num))
    {
        if (c != '\n') clear_buffer();
        printf("This does not seem to be a valid number.\n");
        scanf("%lf", num);
        c = getchar();
    }
}

void print_roots(int roots_amount, double *x1, double *x2)
{
    switch (roots_amount)
    {
        case TWO_ROOTS:
            printf("%.4f; %.4f", min_of_two(*x1, *x2), max_of_two(*x1, *x2));
            break;
        case ONE_ROOT:
            printf("%.4f", *x1);
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
}

void clear_buffer(void)
{
    int c = 0;
    while (c != '\n')
    {
        c = getchar();
    }
}

void ask_for_coeff(char coeff_name, double *coeff_address)
{
    printf("Please enter %c.\n", coeff_name);
    getnum(coeff_address);
}

void get_coeffs(double *a, double *b, double *c)
{
    printf("ax^2 + bx + c = 0\n");
    ask_for_coeff('a', a);
    ask_for_coeff('b', b);
    ask_for_coeff('c', c);
    printf("Solving %.4fx^2 + %.4fx + %.4f = 0\n", *a, *b, *c);
}
