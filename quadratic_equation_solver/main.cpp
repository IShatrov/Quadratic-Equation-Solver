#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define MAX_OF_TWO(n1, n2) ((n1 > n2) ? (n1) : (n2))
#define MIN_OF_TWO(n1, n2) ((n1 > n2) ? (n2) : (n1))
#define RULES "Use point as the decimal separator. Numbers must be shorter than 1000 symbols.\n"
#define EPSILON 0.0000000001

int getnum(double * num);
int solve(double a, double b, double c);
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
    solve(a, b, c);
    return 0;
}

int getnum(double * num)
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
    return 0;
}

int solve(double a, double b, double c)
{
    printf("Solving %.4fx^2 + %.4fx + %.4f = 0\n", a, b, c);
    double d = b * b - 4 * a * c;
    if (!are_doubles_equal(a, 0))
    {
        if (d > 0)
        {
            double sq_d = sqrt(d);
            double x1 = (-b + sq_d) / (2 * a);
            double x2 = (-b - sq_d) / (2 * a);
            printf("%.4f; %.4f", MIN_OF_TWO(x1, x2), MAX_OF_TWO(x1, x2));
        }
        else if (are_doubles_equal(d, 0))
        {
            double x1 = -b / (2 * a);
            printf("%.4f", x1);
        }
        else
        {
            printf("No real solutions.");
        }
    }
    else
    {
        if (are_doubles_equal(b, 0)) printf("%s", (are_doubles_equal(c, 0)) ? "x can be any real number." : "No real solutions.");
        else
        {
            double x1 = -c / b;
            printf("%.4f", x1);
        }
    }
    return 0;
}

int are_doubles_equal(double n1, double n2)
{
    return ((fabs(n1 - n2) <= EPSILON) ? (1) : (0));
}
