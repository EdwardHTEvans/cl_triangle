#include "triangle.h"
#include <math.h>

/*!
    \fn long double triangle_calculate_area(long double a, long double b, long double c)
    \brief Calculates area of triangle when supplied with three side lengths,
    In the event the sides do not make a valid triangle, the area will be 0.
    Implemented using Heron's formula. Subject to rounding error.

    \param a side legnth 1.
    \param b side legnth 2.
    \param c side legnth 3.
*/
long double triangle_herons_formula(long double a, long double b, long double c)
{
    long double s;

    // Heron's formula
    s = (a + b + c) / 2;
    s = sqrt(s * (s - a) * (s - b) * (s - c));
    s = isnan(s) ? 0 : s;
    s = isinf(s) ? 0 : s;
    return s;
}
