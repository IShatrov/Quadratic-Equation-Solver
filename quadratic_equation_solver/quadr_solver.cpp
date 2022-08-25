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

int solve_quadr(double a, double b, double c, double *x1, double *x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (are_doubles_equal (a, 0)) return solve_lin (b, c, x1);

    if (are_doubles_equal(b, 0) && c < 0)
    {
        *x1 = sqrt(-c / a);
        *x2 = -*x1;
        return 2;
    }
    else if (are_doubles_equal(c, 0))
    {
        if (are_doubles_equal(b, 0))
        {
            *x1 = 0;
            return 1;
        }
        *x1 = 0;
        *x2 = -b / a;
        return 2;
    }

    double d = b*b - 4*a*c;

    if (d > 0)
    {
        double sq_d = sqrt(d);
        *x1 = (-b + sq_d) / (2*a);
        *x2 = (-b - sq_d) / (2*a);
        return 2;
    }
    else if (are_doubles_equal(d, 0))
    {
        *x1 = -b / (2*a);
        return 1;
    }
    else
    {
        return 0;
    }
}

int solve_lin(double a, double b, double *x)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(x != NULL);

    if (are_doubles_equal(a, 0))
        return ((are_doubles_equal(b, 0)) ? INF_ROOTS : 0);
    else
    {
        *x = (are_doubles_equal(b, 0) ? 0 : -b / a);
        return 1;
    }
}

int are_doubles_equal(double n1, double n2)
{
    return (fabs(n1 - n2) <= EPSILON);
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

double max_of_two(double n1, double n2)
{
    return (n1 > n2) ? (n1) : (n2);
}

double min_of_two(double n1, double n2)
{
    return (n1 > n2) ? (n2) : (n1);
}
