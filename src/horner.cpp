/**
 * Implementacja schematu Hornera.
 *
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#include "define.h"
#include "horner.h"

Floating horner(Floating coefficients[] /* an, an-1, ..., a0 */, 
                int degree, Floating arg) {

  Floating value;

  // If polynomial is constant.
  if(degree == 0)
    value = coefficients[0];
  // Polynomial isn't constant.
  else {
    // Start with calculating value using coefficient with highest degree.
    value = coefficients[0] * arg;

    // Calculating using following coefficients.
    for(int i = 1; i < degree; ++i)
      value = (value + coefficients[i]) * arg;

     // Last step is adding coefficient with zero degree (a0).
    value += coefficients[degree];
  }

  return value;
}

