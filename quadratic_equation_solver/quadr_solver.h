#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

//! @param[in] condition Condition.
//! @brief If condition is false, prints an error message. Does *not* abort the program.
#define MY_ASSERT(condition)                                                                     \
if (!(condition)) printf("Error %s in line %d in function %s\n", #condition, __LINE__, __func__) \

//! @brief Possible amounts of solutions of the equation.
enum roots_amount {NO_ROOTS, ONE_ROOT, TWO_ROOTS, INF_ROOTS = -1};

//! @brief Determines precision of are_doubles_equal().
const double EPSILON = 1e-7;

//! @param[in] num Pointer to the number.
//! @brief Reads input data. If the data is not a valid number prints "This does not seem to be a valid number" and tries to read again.
void getnum(double *num);

//! @param[in] roots_amount Amount of the solutions of the equation.
//! @param[in] x1 Pointer to x1.
//! @param[in] x2 Pointer to x2.
//! @brief Prints the solutions of the equation if they exits. Prints "x can be any real number." if there are infinite solutions and "No real solutions." if there are no real solutions.
void print_roots(int roots_amount, double *x1, double *x2);

//! @param[in] a a-coefficient of the equation.
//! @param[in] b b-coefficient of the equation.
//! @param[in] c c-coefficient of the equation.
//! @param[out] x1 Pointer to one of the solutions of the equation.
//! @param[out] x2 Pointer to one of the solutions of the equation.
//! @return Returns the amount of the solutions of the equation and INF_ROOTS if the equation has infinite solutions.
//! @brief Solves equation ax^2 + bx + c = 0
int solve_quadr(double a, double b, double c, double *x1, double *x2);

//! @param[in] a a-coefficient of the equation.
//! @param[in] b b-coefficient of the equation.
//! @param[out] x Pointer to the solution of the equation.
//! @return Returns the amount of the solutions of the equation and INF_ROOTS if the equation has infinite solutions.
//! @brief Solves equation ax + b = 0
int solve_lin(double a, double b, double *x);

//! @param[in] n1 First number.
//! @param[in] n2 Second number.
//! @return Returns 1 or 0.
//! @brief Returns 1 if |n1 - n2| <= EPSILON and 0 otherwise.
int are_doubles_equal(double n1, double n2);

//! @brief Clears input buffer using getchar() function.
void clear_buffer(void);

//! @param[in] coeff_name Name of the coefficient.
//! @param[in] coeff_address Pointer to the coefficient.
//! @brief Prints a prompt and reads input data using getnum() function.
void ask_for_coeff(char coeff_name, double *coeff_address);

//! @param[out] a Pointer to a-coefficient of the equation.
//! @param[out] b Pointer to b-coefficient of the equation.
//! @param[out] c Pointer to c-coefficient of the equation.
//! @brief Gets coefficients of the equation.
void get_coeffs(double *a, double *b, double *c);

//! @param[in] n1 First number.
//! @param[in] n2 Second number.
//! @return Returns n1 if n1 > n2 and n2 otherwise.
//! @brief Identifies which of two numbers is larger.
double max_of_two(double n1, double n2);

//! @param[in] n1 First number.
//! @param[in] n2 Second number.
//! @return Returns n2 if n1 > n2 and n2 otherwise.
//! @brief Identifies which of two numbers is smaller.
double min_of_two(double n1, double n2);

//! @param[in] a a-coefficient of the equation.
//! @param[in] b b-coefficient of the equation.
//! @param[in] c c-coefficient of the equation.
//! @param[in] expected_nRoots Expected amount of the solutions of the equation.
//! @param[in] expected_x1 Expected x1.
//! @param[in] expected_x2 Expected x2.
//! @brief Tests if solve_quadr() works as expected.
void test_eq(double a, double b, double c, int expected_nRoots, double expected_x1, double expected_x2);

//! @brief Launches the tests. Gets test data from test_eq_data.txt file. Prints an error message if the file was not found.
void start_tests(void);
