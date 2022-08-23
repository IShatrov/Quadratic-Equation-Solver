#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define MAX_OF_TWO(n1, n2) ((n1 > n2) ? (n1) : (n2))
#define MIN_OF_TWO(n1, n2) ((n1 > n2) ? (n2) : (n1))
#define RULES "Use point as the decimal separator. Numbers must be shorter than 1000 symbols.\n"
#define EPSILON 0e-7
#define INF 2e6

void getnum(double * num);
int solve(double a, double b, double c, double * x1, double * x2);
int are_doubles_equal(double n1, double n2);

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
    printf("Solving %.4fx^2 + %.4fx + %.4f = 0\n", a, b, c);
    double x1 = NAN, x2 = NAN;
    int roots_amount = solve(a, b, c, &x1, &x2);
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
        case INF:
            printf("x can be any real number.");
            break;
        default:
            printf("error");
            break;
    }
    return 0;
}

void getnum(double * num)
{
    assert(num);
    double n = NAN;
    scanf("%lf", &n);
    int c = getchar();
    while (c != '\n')
    {
        while (c != '\n')
        {
            c = getchar();
        }
        printf("This does not seem to be a valid number. %s", RULES);
        scanf("%lf", &n);
        c = getchar();
    }
    *num = n;
}

int solve(double a, double b, double c, double * x1, double * x2)
{
    assert(x1);
    assert(x2);
    double d = b * b - 4 * a * c;
    if (!are_doubles_equal(a, 0))
    {
        if (d > 0)
        {
            double sq_d = sqrt(d);
            *x1 = (-b + sq_d) / (2 * a);
            *x2 = (-b - sq_d) / (2 * a);
            return 2;
        }
        else if (are_doubles_equal(d, 0))
        {
            *x1 = -b / (2 * a);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (are_doubles_equal(b, 0)) return ((are_doubles_equal(c, 0)) ? INF : 0);
        else
        {
            *x1 = -c / b;
            return 1;
        }
    }
    return -1;
}

int are_doubles_equal(double n1, double n2)
{
    return ((fabs(n1 - n2) <= EPSILON) ? (1) : (0));
}
