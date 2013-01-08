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

  return 0;
}
