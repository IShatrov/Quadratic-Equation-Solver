#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define MAX_OF_TWO(n1, n2) ((n1 > n2) ? (n1) : (n2))
#define MIN_OF_TWO(n1, n2) ((n1 > n2) ? (n2) : (n1))
#define RULES "Use point as the decimal separator. Numbers must be shorter than 1000 symbols.\n"
#define EPSILON 1e-7
#define INF_ROOTS 3

void getnum(double *num);
int solve_quadr(double a, double b, double c, double *x1, double *x2);
int solve_lin(double a, double b, double *x);
int are_doubles_equal(double n1, double n2);
void clear_buffer(void);

int main(void)
{
    double a = NAN, b = NAN, c = NAN;

    printf("ax^2 + bx + c = 0\n");
    printf(RULES);
    printf("Please enter a.\n");
    getnum(&a);
    printf("Please enter b.\n");
    getnum(&b);
    printf("Please enter c.\n");
    getnum(&c);

    double x1 = NAN, x2 = NAN;
    int roots_amount = solve_quadr(a, b, c, &x1, &x2);

    printf("Solving %.4fx^2 + %.4fx + %.4f = 0\n", a, b, c);
    switch (roots_amount)
    {
        case 2:
            printf("%.4f; %.4f", MIN_OF_TWO(x1, x2), MAX_OF_TWO(x1, x2));
            break;
        case 1:
            printf("%.4f", x1);
            break;
        case 0:
            printf("No real solutions.");
            break;
        case INF_ROOTS:
            printf("x can be any real number.");
            break;
        default:
            printf("error");
            break;
    }
    return 0;
}

void getnum(double *num)
{
    assert(num != NULL);

    *num = NAN;
    scanf("%lf", num);
    int c = getchar();

    while (c != '\n')
    {
        clear_buffer();
        printf("This does not seem to be a valid number. %s", RULES);
        scanf("%lf", num);
        c = getchar();
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

    double d = b*b - 4*a*c;
    if (!are_doubles_equal(a, 0))
    {
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
    return solve_lin(b, c, x1);
}

int solve_lin(double a, double b, double *x)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(x != NULL);

    if (are_doubles_equal(a, 0)) return ((are_doubles_equal(b, 0)) ? INF_ROOTS : 0);
    else
    {
        *x = -b / a;
        return 1;
    }
}

int are_doubles_equal(double n1, double n2)
{
    assert(isfinite(n1));
    assert(isfinite(n2));

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
