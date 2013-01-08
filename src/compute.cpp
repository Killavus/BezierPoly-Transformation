/**
 * Metody obliczania wartości wielomianów - de Casteljau, 
 * oraz schemat Hornera.
 *
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#include "generic.h"

/**
 * Implementacja schematu Hornera.
 **/
Floating horner(Floating coefficients[] /* an, an-1, ..., a0 */, 
                int degree, Floating arg) {

  Floating value;

  if(degree == 0)
    value = coefficients[0];
  else {
    value = coefficients[0] * arg;

    for(int i = 1; i < degree; ++i)
      value = (value + coefficients[i]) * arg;

    value += coefficients[degree];
  }

  return value;
}

/**
 * Implementacja algorytmu de Casteljau.
 **/
Floating de_casteljau(Floating coefficients[] /* an, an-1, ..., a0 */,
                      int degree, Floating arg) {
  Floating value;

  if(degree == 0)
    value = coefficients[0];
  else {
    Floating results[degree + 1];
    int i, j;

    // Przepisujemy tablicę odwrotnie. Wartości będziemy liczyć w miejscu.
    for(i = 0; i <= degree; ++i)
      results[degree - i] = coefficients[i];

    for(i = 0; i < degree; ++i) {
      for(j = 0; j < (degree - i); j++)
        results[j] = (1 - arg) * results[j] + arg * results[j + 1];
    }

    value = results[0];
  }

  return value;
}
