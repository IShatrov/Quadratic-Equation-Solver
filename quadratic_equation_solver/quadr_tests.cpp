#include "quadr_solver.h"

void test_eq(double a, double b, double c, int expected_nRoots, double expected_x1, double expected_x2)
{
        double x1 = NAN, x2 = NAN;
        int nRoots = solve_quadr(a, b, c, &x1, &x2);
        switch (nRoots)
        {
            case TWO_ROOTS:
                MY_ASSERT(nRoots == expected_nRoots);
                MY_ASSERT(are_doubles_equal(x1, expected_x1));
                MY_ASSERT(are_doubles_equal(x2, expected_x2));
                break;
            case ONE_ROOT:
                MY_ASSERT(nRoots == expected_nRoots);
                MY_ASSERT(are_doubles_equal(x1, expected_x1));
                MY_ASSERT(isnan(x2));
                break;
            case NO_ROOTS:
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
    FILE *test_data = NULL;
    test_data = fopen("test_eq_data.txt", "r");

    int ch = '0';
    char a[20], b[20], c[20], expected_x1[20], expected_x2[20], expected_nRoots[20];

    while (ch != EOF)
    {
        fscanf(test_data, "%s %s %s %s %s %s", a, b, c, expected_nRoots, expected_x1, expected_x2);
        ch = getc(test_data);
        test_eq(strtod(a, '\0'), strtod(b, '\0'), strtod(c, '\0'), atoi(expected_nRoots), strtod(expected_x1, '\0'), strtod(expected_x2, '\0'));
    }

    if (fclose(test_data) == 0) printf("Test data file closed successfully\n");

    printf("Tests finished\n");
}
