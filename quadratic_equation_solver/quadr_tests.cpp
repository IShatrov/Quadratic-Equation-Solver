#include "quadr_solver.h"

//! @brief Determines maximal length of a number in test_eq_data.txt file.
const int TEST_NUMBER_LENGTH = 20;

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

    if ((test_data = fopen("test_eq_data.txt", "r")))
    {
        int ch = '0';
        char a[TEST_NUMBER_LENGTH] = "0", b[TEST_NUMBER_LENGTH] = "0", c[TEST_NUMBER_LENGTH] = "0",
          expected_x1[TEST_NUMBER_LENGTH] = "0", expected_x2[TEST_NUMBER_LENGTH] = "0", expected_nRoots[TEST_NUMBER_LENGTH] = "0";
        while (ch != EOF)
        {
            fscanf(test_data, "%s %s %s %s %s %s", a, b, c, expected_nRoots, expected_x1, expected_x2);
            ch = getc(test_data);
            test_eq(strtod(a, '\0'), strtod(b, '\0'), strtod(c, '\0'), atoi(expected_nRoots), strtod(expected_x1, '\0'), strtod(expected_x2, '\0'));
        }

        if (fclose(test_data) == 0) printf("Test data file closed successfully\n");

        printf("Tests finished\n");
    }
    else
    {
        printf("test_eq_data.txt not found\n");
    }
}

//There must be a better way to read NANs from file!

