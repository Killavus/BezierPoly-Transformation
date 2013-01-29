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

Floating pascal[PASCAL_SIZE * PASCAL_SIZE];

int main(void) {
  pascal_populate(pascal);

  Floating poly1[5] = {1,-6,11,-6,0},
           poly2[11] = {2,-31,44,204,13,-287,159,60,-29,-48,144},
           poly3[13] = {-3,-8,7,4,-40,-60,-54,-18,109,0,-2,29,24},
           poly4[21] = {-7,62,-79,16,-97,-4,-11,28,25,-193,285,-226,13,-6,-7,-15,-51,168,-26,4,-16},
           max[21];
  
  std::cout << "POLY1 test:" << std::endl;
  std::cout.setf(std::ios::fixed,std::ios::floatfield);
  std::cout.precision(50);
  
  for (int i = 1; i <= 1000000; ++i) {
    to_bezier_form(pascal, 4, poly1, max);
    to_exp_form(pascal, 4, max, poly1);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << i << " " << horner(poly1, 4, 1) << std::endl;
    }
  }

  std::cout << "POLY2 test:" << std::endl;
  for (int i = 1; i <= 1000000; ++i) {
    to_bezier_form(pascal, 10, poly2, max);
    to_exp_form(pascal, 10, max, poly2);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << i << " " << horner(poly2, 10, 4) << std::endl;
    }
  }

  std::cout << "POLY3 test:" << std::endl;
  for (int i = 1; i <= 1000000; ++i) {
    to_bezier_form(pascal, 12, poly3, max);
    to_exp_form(pascal, 12, max, poly3);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << i << " " << horner(poly3, 12, -3) << std::endl;
    }
  }

  std::cout << "POLY4 test:" << std::endl;
  for (int i = 1; i <= 1000000; ++i) {
    to_bezier_form(pascal, 20, poly4, max);
    to_exp_form(pascal, 20, max, poly4);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << i << " " << horner(poly4, 20, 2) << std::endl;
    }
  }
  
  return 0;
}
