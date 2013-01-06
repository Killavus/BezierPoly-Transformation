/**
 * Implementacja algorytmu de Casteljau.
 *
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#include <stdio.h>

typedef long double Floating;

inline bool isPolynomialConstant(int degree) { return degree == 0; }

Floating deCasteljauAlgorithm(Floating coefficients[] /* an, an-1, ..., a0 */,
                                int degree, Floating arg) {
  Floating value;
  if(isPolynomialConstant(degree))
  {
    value = coefficients[0];
  }
  else
  {
    Floating deCasteljau[degree + 1];
    int i, j;

    // Filling the zero-th values into the array.
    for(i = 0; i < degree; ++i)
    {
      deCasteljau[i] = coefficients[i];
    }

    // Calculating following values.
    for(i = 0; i < degree; ++i)
    {
      for(j = 0; j < degree - i; j++)
      {
        deCasteljau[j] = (1 - arg) * coefficients[j] + arg * coefficients[j + 1];
      }
    }

    // Last calculated value is the result.
    return deCasteljau[0];
  }
}  

// int main(void) {
//   Floating coeff1[3] = { 1.0, 1.0, 0.0 };
//   Floating coeff2[1] = { 1337.0 };

//   printf("%llf\n", deCasteljauAlgorithm(coeff1, 2, 1.0));
//   printf("%llf\n", deCasteljauAlgorithm(coeff2, 0, 23829.372));

//   return 0;
// }
