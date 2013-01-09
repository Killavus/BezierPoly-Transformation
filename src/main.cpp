/**
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/

#include <iostream>

#include "generic.h"
#include "pascal.h"
#include "compute.h"
#include "transform.h"

int pascal[PASCAL_SIZE * PASCAL_SIZE];

int main(void) {
  std::cout << "Populating the Pascal triangle..." << std::endl;
  pascal_populate(pascal);

  Floating exp_coeffs[3] = { 2.0, 3.0, 2.0 };
  Floating bez_coeffs[3];

  to_bezier_form(pascal, 2, exp_coeffs, bez_coeffs);
  for(int i = 0; i < 3; ++i) {
    std::cout << bez_coeffs[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
