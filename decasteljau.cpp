/**
 * Implementacja algorytmu de Casteljau.
 *
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#include <iostream>

typedef long double Floating;

inline bool isPolynomialConstant(int degree) { return degree == 0; }

Floating deCasteljauAlgorithm(Floating coefficients[] /* an, an-1, ..., a0 */,
                                int degree, Floating arg) {
  Floating value;
  if(isPolynomialConstant(degree))
    value = coefficients[0];
  else {
    Floating deCasteljau[degree + 1];
    int i, j;

    // Filling the zero-th values into the array.
    for(i = 0; i <= degree; ++i)
      deCasteljau[i] = coefficients[i];

    // Calculating following values.
    for(i = 0; i < degree; ++i) {
      for(j = 0; j <= (degree - i); j++)
        deCasteljau[j] = (1 - arg) * deCasteljau[j] + arg * deCasteljau[j + 1];
    }

    // Last calculated value is the result.
    return deCasteljau[0];
  }
}  

int main(void) {
  Floating coeff[3] = { 7.0, 3.5, 2.0 };

  std::cout << deCasteljauAlgorithm(coeff, 2, 1.0) << std::endl;
  std::cout << deCasteljauAlgorithm(coeff, 2, 0.75) << std::endl;
  std::cout << deCasteljauAlgorithm(coeff, 2, 0.5) << std::endl;

  return 0;
}
