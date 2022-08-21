#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX_OF_TWO(n1, n2) ((n1 > n2) ? (n1) : (n2))
#define MIN_OF_TWO(n1, n2) ((n1 > n2) ? (n2) : (n1))
#define RULES "Use point as the decimal separator. Numbers must be shorter than 1000 symbols.\n"

int getnum(float * num);

int main(void)
{
    float a = 0, b = 0, c = 0, x1 = 0, x2 = 0, d = 0;

    printf("ax^2 + bx + c = 0\n");
    printf(RULES);
    printf("Please enter a.\n");
    getnum(&a);
    printf("Please enter b.\n");
    getnum(&b);
    printf("Please enter c.\n");
    getnum(&c);
    printf("Solving %.4fx^2 + %.4fx + %.4f = 0\n", a, b, c);

    d = b * b - 4 * a * c;
    if (a)
    {
        if (d > 0)
        {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            printf("%.4f; %.4f", MIN_OF_TWO(x1, x2), MAX_OF_TWO(x1, x2));
        }
        else if (d == 0)
        {
            x1 = -b / (2 * a);
            printf("%.4f", x1);
        }
        else
        {
            printf("No real solutions.");
        }
    }
    else
    {
        if (b == 0) printf("%s", (c == 0) ? "x can be any real number." : "No real solutions.");
        else
        {
            x1 = -c / b;
            printf("%.4f", x1);
        }
    }
    return 0;
}

int getnum(float * num)
{
    char current_char = '0', input[1050];
    int allright_flag = 1, minus_flag = 0, point_flag = 0, i = 1;
    while (1)
    {
        allright_flag = 1;
        minus_flag = 0;
        point_flag = 0;
        i = 1;
        current_char = getchar();
        if (isdigit(current_char) || current_char == '-')
        {
            minus_flag = (current_char == '-');
            input[0] = current_char;
            current_char = getchar();
        }
        else allright_flag = 0;
        while (current_char != '\n')
        {
            if (allright_flag && (isdigit(current_char) || (current_char == '.' && minus_flag && i >= 2 && !point_flag) ||
                 (current_char == '.' && !minus_flag && i >= 1 && !point_flag)) && (i < 1000))
            {
                input[i] = current_char;
                i++;
                point_flag += (current_char == '.');
                current_char = getchar();
            }
            else
            {
                allright_flag = 0;
                current_char = getchar();
            }
        }
        input[i] = '\0';
        if (allright_flag && !(input[0] == '-' && input[1] == '\0'))
        {
            *num = atof(input);
            return 1;
        }
        else printf("This does not seem to be a valid number. %s", RULES);
    }
}
