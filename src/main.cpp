/**
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/

#include <iostream>

#include "define.h"
#include "horner.h"
#include "decasteljau.h"
#include "pascal.h"

int pascal[PASCAL_SIZE * PASCAL_SIZE];

int main(void) {
  std::cout << "Populating the Pascal triangle..." << std::endl;
  pascal_populate(pascal);
  std::cout << "Some values: " << 
    pascal_value(pascal, 2, 1) << " " <<
    pascal_value(pascal, 3, 2) << " " <<
    pascal_value(pascal, 3, 1) << " " <<
  std::endl;

  std::cout << "Testing Horner scheme with some coefficients: " << std::endl;
  Floating coeff1[3] = { 2.0, 3.0, 2.0 };

  std::cout << horner(coeff1, 2, 1.0) << std::endl;
  std::cout << horner(coeff1, 2, 0.75) << std::endl;
  std::cout << horner(coeff1, 2, 0.5) << std::endl << std::endl;

  std::cout << "Testing de Casteljau algorithm with some coefficients: " << std::endl;
  Floating coeff2[3] = { 7.0, 3.5, 2.0 };

  std::cout << de_casteljau(coeff2, 2, 1.0) << std::endl;
  std::cout << de_casteljau(coeff2, 2, 0.75) << std::endl;
  std::cout << de_casteljau(coeff2, 2, 0.5) << std::endl << std::endl;

  return 0;
}
