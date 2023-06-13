#include "triangle.h"
#include <math.h>

/*!
    \fn double triangle_calculate_area(double a, double b, double c)
    \brief Calculates area of triangle when supplied with three side lengths,
    In the event the sides do not make a valid triangle, the area will be 0.
    Implemented using Heron's formula.

    \param a One of three sides of a triangle.
    \param b One of three sides of a triangle.
    \param c One of three sides of a triangle
*/
double triangle_herons_formula(double a, double b, double c)
{
    double s;

    // Heron's formula
    s = (a + b + c) / 2;
    s = sqrt(s * (s - a) * (s - b) * (s - c));
    s = isnan(s) ? 0 : s;
    return s;
}
