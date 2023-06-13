#include <float.h>
#include <regex.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "triangle.h"

/*!
    \fn int main(int argc, char **argv)
    \brief This main function wraps the triangle area calculation utility
    with a command line interface with sanitised inputs
*/
int main(int argc, char **argv)
{
    regex_t regex;
    double sides[3];
    double area;
    unsigned int index;

    // --help option
    if (argc == 2 && strcmp(argv[1], "--help") == 0)
    {
        printf("%s",
            "Usage: cl_triangle [a] [b] [c]...\r\n"
            "\r\n"
            "command line tool for calculating the area of a triangle based on the length of its sides using Heron's formula.\r\n"
            "\r\n"
            "Options:\r\n"
            "  -h, --help             show help\r\n"
            "\r\n"
            "Examples:\r\n"
            "cl_triangle 3.5 4.5 5.5\r\n"
        );
        return 0;
    }

    // make sure the user has supplied enough sides
    if (argc < 4)
    {
        printf("Error: missing operands\r\n");
        return -1;
    }

    // warn the user to which three sides are to be used in the calculation, 
    // in the event more then three are supplied
    if (argc > 4)
    {
        printf("Warning: ignoring extra operands, using first three\r\n");
    }

    // regex compiled to match integers and decimals for input sanitisation
    if (regcomp(&regex, "^[0-9]+.?[0-9]*", REG_EXTENDED))
    {
        printf("Error: could not compile regex\r\n");
        return -1;
    }

    // iterate over user supplied sides and check if they are valid integers or decimals
    for (index = 1; index < 4; index++)
    {
        if (regexec(&regex, argv[index], 0, NULL, 0))
        {
            printf("Error: argument %d [%s] is invalid\n\r", index, argv[index]);
            return -1;
        }

        // input is valid, we can now convert it to a double
        sides[index - 1] = atof(argv[index]);
    }

    // actual calculation is done in separate file, for portability sake
    area = triangle_herons_formula(sides[0], sides[1], sides[2]);

    // triangle is defined by having three edges, an area of 0 means it's a line (one edge)
    if (!area)
    {
        printf("Error: supplied sides do not make a valid triangle\n\r");
    }
    else
    {
        printf("Info: area = %.3f m^2\n\r", area);
    }

    return 0;
}
