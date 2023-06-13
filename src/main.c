#include <float.h>
#include <regex.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "triangle.h"

/*!
    \fn int main(int argc, char **argv)
    \brief This main function wraps triangle_herons_formula
    with a command line interface with sanitised inputs.
*/
int main(int argc, char **argv)
{
    regex_t regex;
    double sides[3];
    double area;
    unsigned int index;

    // make sure the user has supplied enough sides
    if (argc < 4)
    {
        printf("Error: missing operands\r\n");
        return 0;
    }

    // make sure the user has not supplied too many sides
    if (argc > 4)
    {
        printf("Error: too many operands\r\n");
        return 0;
    }

    // regex compiled to match integers and decimals for input sanitisation
    if (regcomp(&regex, "^[[0-9]+\\.?[0-9]*(e[+-]+[0-9]+)?$", REG_EXTENDED))
    {
        printf("Error: could not compile regex\r\n");
        return 0;
    }

    // iterate over user supplied sides and check if they are valid integers or decimals
    for (index = 1; index < 4; index++)
    {
        if (regexec(&regex, argv[index], 0, NULL, 0))
        {
            printf("Error: argument %d [%s] is invalid\r\n", index, argv[index]);
            return 0;
        }

        // input is valid, we can now convert it to a double
        sides[index - 1] = atof(argv[index]);
    }

    // actual calculation is done in separate file, for portability
    area = triangle_herons_formula(sides[0], sides[1], sides[2]);

    // no area means its not a valid solid polygon
    if (!area)
    {
        printf("Error: invalid input\r\n");
        return 0;
    }

    printf("%e\r\n", area);

    return 0;
}
