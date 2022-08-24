#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define MY_ASSERT(condition)                                                                     \
if (!(condition)) printf("Error %s in line %d in function %s\n", #condition, __LINE__, __func__) \

enum roots_amount {NO_ROOTS, ONE_ROOT, TWO_ROOTS, INF_ROOTS = -1};
const double EPSILON = 1e-7;

//! @param[in] num Pointer to double to store received number at.
//! @note Reads input data. If the data is not a valid number prints "This does not seem to be a valid number" and tries to read again.
void getnum(double *num);

//! @param[in] a a-coefficient of the equation.
//! @param[in] b b-coefficient of the equation.
//! @param[in] c c-coefficient of the equation.
//! @param[out] x1 Pointer to one of the solutions of the equation.
//! @param[out] x2 Pointer to one of the solutions of the equation.
//! @return Returns the amount of the solutions of the equation and INF_ROOTS if the equation has infinite solutions.
//! @note Solves equation ax^2 + bx + c = 0
int solve_quadr(double a, double b, double c, double *x1, double *x2);

//! @param[in] a a-coefficient of the equation.
//! @param[in] b b-coefficient of the equation.
//! @param[out] x Pointer to the solution of the equation.
//! @return Returns the amount of the solutions of the equation and INF_ROOTS if the equation has infinite solutions.
//! @note Solves equation ax + b = 0
int solve_lin(double a, double b, double *x);

//! @param[in] n1 First number.
//! @param[in] n2 Second number.
//! @return Returns 1 or 0.
//! @note Returns 1 if |n1 - n2| <= EPSILON and 0 otherwise.
int are_doubles_equal(double n1, double n2);

//! @note Clears input buffer using getchar function.
void clear_buffer(void);

//! @param[out] a Pointer to a-coefficient of the equation.
//! @param[out] b Pointer to b-coefficient of the equation.
//! @param[out] c Pointer to c-coefficient of the equation.
//! @note Gets coefficients of the equation.
void get_coeff(double *a, double *b, double *c);

//! @param[in] n1 First number.
//! @param[in] n2 Second number.
//! @return Returns n1 if n1 > n2 and n2 otherwise.
double max_of_two(double n1, double n2);

//! @param[in] n1 First number.
//! @param[in] n2 Second number.
//! @return Returns n2 if n1 > n2 and n2 otherwise.
double min_of_two(double n1, double n2);

//! @param[in] a a-coefficient of the equation.
//! @param[in] b b-coefficient of the equation.
//! @param[in] c c-coefficient of the equation.
//! @param[in] expected_nRoots Expected amount of the solutions of the equation.
//! @param[in] expected_x1 Expected x1.
//! @param[in] expected_x2 Expected x2.
//! @note Tests if solve_quadr() works as expected.
void test_eq(double a, double b, double c, int expected_nRoots, double expected_x1, double expected_x2);

//!> @note Launches the tests.
void start_tests(void);

int main(void)
{
    start_tests();

    double a = NAN, b = NAN, c = NAN;

    get_coeff(&a, &b, &c);

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

    return 0;
}

void getnum(double *num)
{
    assert(num != NULL);

    scanf("%lf", num);
    int c = getchar();

    while (c != '\n')
    {
        clear_buffer();
        printf("This does not seem to be a valid number.\n");
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

    if (are_doubles_equal (a, 0)) return solve_lin (b, c, x1);

    double d = b*b - 4*a*c;
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
    else if (d > 0)
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

void get_coeff(double *a, double *b, double *c)
{
    printf("ax^2 + bx + c = 0\n");
    printf("Please enter a.\n");
    getnum(a);
    printf("Please enter b.\n");
    getnum(b);
    printf("Please enter c.\n");
    getnum(c);
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

void test_eq(double a, double b, double c, int expected_nRoots, double expected_x1, double expected_x2)
{
        double x1 = NAN, x2 = NAN;
        int nRoots = solve_quadr(a, b, c, &x1, &x2);
        switch (nRoots)
        {
            case 2:
                MY_ASSERT(nRoots == expected_nRoots);
                MY_ASSERT(are_doubles_equal(x1, expected_x1));
                MY_ASSERT(are_doubles_equal(x2, expected_x2));
                break;
            case 1:
                MY_ASSERT(nRoots == expected_nRoots);
                MY_ASSERT(are_doubles_equal(x1, expected_x1));
                MY_ASSERT(isnan(x2));
                break;
            case 0:
                MY_ASSERT(nRoots == expected_nRoots);
                MY_ASSERT(isnan(x1));
                MY_ASSERT(isnan(x2));
                break;
            case INF_ROOTS:
                MY_ASSERT(nRoots == expected_nRoots);
                MY_ASSERT(isnan(x1));
                MY_ASSERT(isnan(x2));
                break;
            default:
                printf("Testing error");
        }
}

void start_tests(void)
{
    test_eq(1.21, -10.116, -1.2, 2, 8.4773175303, -0.1169869518);
    test_eq(1, 2, 1, 1, -1, NAN);
    test_eq(100, 1, 1, 0, NAN, NAN);
    test_eq(5, 0, 0, 1, 0, NAN);
    test_eq(1, 0, 1, 0, NAN, NAN);
    test_eq(0, 0, 0, INF_ROOTS, NAN, NAN);
    test_eq(1, 2, 0, 2, 0, -2);
    test_eq(0, 0, 1, 0, NAN, NAN);
    test_eq(0, 2, 0, 1, 0, NAN);
    test_eq(0, 2, 4, 1, -2, NAN);
}
