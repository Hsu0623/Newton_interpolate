#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <GL/glut.h>


//Define PI
#define  PI 3.14159


// Define the 2 ends of the domain.
#define  A  0.0
#define  B  1.0


// define the max index of sample points.
// There are (N+1) sample points.
#define  N  9

// Define the number of points generated when drawing the functions.
#define  NUM_PNT    40


//define gap between sample points.
#define  h          (B-A)/N




//define frequency of cos(x)
#define  F 4

/*---------------------------------------------------------
 * Procedure to compute the coefficients of Newton
 * polynomial.
 *   data[][2]: sample points, (xi, yi)
 *   n: largest index of sample point.
 * Return the interpolated value.
 */
void comp_Newton_coef(double data[][2], int n);

/*-------------------------------------------------------------
 * Procedure to perform Newton polynomial interpolation.
 *   data[][2]: the sample points,
 *   t: the input parameter value,
 *   n: last index of sample pnt.
 * Return the interpolayed value.
 */
double Newton_interpolate(double data[][2], double t, int n);

/*---------------------------------------------------------
 * Procedure to compute the Chord Length
 *   data[][2]: sample points, (xi, yi)
 *   n: largest index of sample point.
 * Return the chord length (double*)
 */
double* chord_length(double data[][2], int n);


