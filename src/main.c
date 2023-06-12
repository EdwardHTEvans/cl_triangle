#include <stdio.h>
#include "triangle.h"

int main(int argc, char **argv)
{
    double a, b, c;
    double area;
    a = 3;
    b = 4;
    c = 6;
    area = triangle_calculate_area(a, b, c);

    printf("%.3f\n\r", area);

    return 0;
}
