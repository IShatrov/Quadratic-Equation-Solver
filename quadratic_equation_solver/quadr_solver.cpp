#include "quadr_solver.h"

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

double max_of_two(double n1, double n2)
{
    return (n1 > n2) ? (n1) : (n2);
}

double min_of_two(double n1, double n2)
{
    return (n1 > n2) ? (n2) : (n1);
}

