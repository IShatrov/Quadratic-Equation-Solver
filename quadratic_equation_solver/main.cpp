#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define MAX_OF_TWO(n1, n2) ((n1 > n2) ? (n1) : (n2))
#define MIN_OF_TWO(n1, n2) ((n1 > n2) ? (n2) : (n1))
#define RULES "Use point as the decimal separator. Numbers must be shorter than 1000 symbols.\n"
#define ZERO 0.0000000001

int getnum(double * num);
int solve(double a, double b, double c);

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
    char trash[1000];
    int c = getchar();
    while (c != '\n')
    {
        printf("This does not seem to be a valid number. %s", RULES);
        scanf("%s", trash);
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
    if (a > ZERO || a < -ZERO)
    {
        if (d > 0)
        {
            double sq_d = sqrt(d);
            double x1 = (-b + sq_d) / (2 * a);
            double x2 = (-b - sq_d) / (2 * a);
            printf("%.4f; %.4f", MIN_OF_TWO(x1, x2), MAX_OF_TWO(x1, x2));
        }
        else if (fabs(d - ZERO) <= ZERO)
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
        if (fabs(b - ZERO) <= ZERO) printf("%s", (fabs(c - ZERO) <= ZERO) ? "x can be any real number." : "No real solutions.");
        else
        {
            double x1 = -c / b;
            printf("%.4f", x1);
        }
    }
    return 0;
}
