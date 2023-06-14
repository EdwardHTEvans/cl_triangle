#include <float.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "triangle.h"

/*!
    \fn int main(int argc, char **argv)
    \brief This main function wraps triangle_herons_formula
    with a command line interface with sanitised inputs.
    \warning result is subject to floating point error, 
    sizes smaller then 1e-150 and larger then 1e+150 are untested 
*/
int main(int argc, char **argv)
{
    char user_inputs[3][MAX_USER_INPUT];

    long double sides[3];
    long double area;
    unsigned int index;

    switch (argc)
    {
    case 0:
    case 1:
        for (index = 0; index < 3;index++)
        {
            printf("cl_triangle: please enter length of side %d:\r\n", index + 1);
            fgets(user_inputs[index], MAX_USER_INPUT, stdin);

            // trim user input upto either \r or \n
            user_inputs[index][strcspn(user_inputs[index], "\r\n")] = 0;
        }
        break;
    case 4:
        for (index = 0; index < 3;index++)
        {
            if (strlen(argv[index]) > MAX_USER_INPUT)
            {
                printf("cl_triangle: argument %d [%s] too long, max length is %d\r\n", index + 1, argv[index], MAX_USER_INPUT);
                return 0;
            }
            strcpy(user_inputs[index], argv[index]);
        }
    default:
        // make sure the user has supplied enough sides
        if (argc < 4)
        {
            printf("cl_triangle: missing arguments\r\n");
            return 0;
        }

        // make sure the user has not supplied too many sides
        if (4 < argc)
        {
            printf("cl_triangle: too many arguments\r\n");
            return 0;
        }
        break;
    }

    // iterate over user supplied sides and check if they are valid integers or decimals
    for (index = 0; index < 3; index++)
    {
        if (check_user_input(user_inputs[index]))
        {
            printf("cl_triangle: argument %d [%s] is invalid\r\n", index + 1, user_inputs[index]);
            return 0;
        }

        // input is valid, we can now convert it to a double
        sides[index] = strtold(user_inputs[index], NULL);
    }

    // actual calculation is done in separate file, for portability
    area = triangle_herons_formula(sides[0], sides[1], sides[2]);

    // no area means its not a valid triangle
    if (!area)
    {
        printf("cl_triangle: invalid input\r\n");
        return 0;
    }

    // output area
    printf("%Le\r\n", area);

    return 0;
}

/*!
    \fn int check_user_input(char *input)
    \brief this functions checks the passed string "input" is in a valid
    integer, decimal, or exponent format, ready to be passed to atof()
    \return returns non-zero if input is invalid
*/
int check_user_input(char *input)
{
    unsigned int index;
    enum check_user_input_state state = DIGITS;

    // iterate over input string
    for (index = 0; index < strlen(input); index++)
    {
        // FSM checks 
        switch (state)
        {
            case DIGITS:
                if (input[index] == '.')
                {
                    state = DECIMAL;
                }
                else if (!isdigit((unsigned char)input[index]))
                {
                    return 1;
                }
                break;

            case DECIMAL:
                if (input[index] == 'e')
                {
                    state = EXPONENT_SIGN;
                }
                else if (!isdigit((unsigned char)input[index]))
                {
                    return 1;
                }
                break;

            case EXPONENT_SIGN:
                if (input[index] == '-' || input[index] == '+')
                {
                    state = EXPONENT;
                }
                else
                {
                    return 1;
                }
                break;

            case EXPONENT:
                if (!isdigit((unsigned char)input[index]))
                {
                    return 1;
                }
                break;

            default:
                return 1;
        }
    }

    return 0;
}
