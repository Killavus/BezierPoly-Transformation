/**
 * Implementacja schematu Hornera.
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

Floating hornerScheme(Floating coefficients[] /* an, an-1, ..., a0 */, 
                        int degree, Floating arg) {

  Floating value;
  if(isPolynomialConstant(degree))
    value = coefficients[0];
  else {
    value = coefficients[0] * arg;

    for(int i = 1; i < degree; ++i)
      value = (value + coefficients[i]) * arg;

    value += coefficients[degree]; // last step: adding a0.
  }

  return value;
}

Floating deCasteljauAlgorithm(Floating coefficients[] /* an, an-1, ..., a0 */,
                                int degree, Floating arg) {
  Floating value;
  if(isPolynomialConstant(degree))
    value = coefficients[0];
  else {

  }
}  

// int main(void) {
//   Floating coeff1[3] = { 1.0, 1.0, 0.0 };
//   Floating coeff2[1] = { 1337.0 };

//   printf("%llf\n", hornerScheme(coeff1, 2, 1.0));
//   printf("%llf\n", hornerScheme(coeff2, 0, 23829.372));

//   return 0;
// }
