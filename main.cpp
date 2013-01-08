/**
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/

 #include <iostream>

 #include "horner.h"
 #include "decasteljau.h"
 #include "beziertopower.h"
 #include "powertobezier.h"

extern Floating hornerScheme(Floating coefficients[] /* an, an-1, ..., a0 */, int degree, Floating arg);
extern Floating deCasteljauAlgorithm(Floating coefficients[], int degree, Floating arg);

int main(void) {
  std::cout << "hornerScheme test: " << std::endl;
  Floating coeff1[3] = { 2.0, 3.0, 2.0 };

  std::cout << hornerScheme(coeff1, 2, 1.0) << std::endl;
  std::cout << hornerScheme(coeff1, 2, 0.75) << std::endl;
  std::cout << hornerScheme(coeff1, 2, 0.5) << std::endl << std::endl;

  std::cout << "deCasteljauAlgorithm test: " << std::endl;
  Floating coeff2[3] = { 7.0, 3.5, 2.0 };

  std::cout << deCasteljauAlgorithm(coeff2, 2, 1.0) << std::endl;
  std::cout << deCasteljauAlgorithm(coeff2, 2, 0.75) << std::endl;
  std::cout << deCasteljauAlgorithm(coeff2, 2, 0.5) << std::endl << std::endl;

  return 0;
}