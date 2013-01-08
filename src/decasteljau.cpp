/**
 * Implementacja algorytmu de Casteljau.
 *
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#include "define.h"

Floating de_casteljau(Floating coefficients[] /* an, an-1, ..., a0 */,
                      int degree, Floating arg) {
  Floating value;

  // If polynomial is constant.
  if(degree == 0)
    value = coefficients[0];
  // Polynomial isn't constant.
  else {
    Floating results[degree + 1];
    int i, j;

    // Filling the zero-th values into the array.
    for(i = 0; i <= degree; ++i)
      results[degree - i] = coefficients[i];

    // Calculating following values.
    for(i = 0; i < degree; ++i) {
      for(j = 0; j < (degree - i); j++)
        results[j] = (1 - arg) * results[j] + arg * results[j + 1];
    }

    // Last calculated value is the result.
    return results[0];
  }
}

