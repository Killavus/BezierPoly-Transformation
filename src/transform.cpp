/**
 * Przekształcenia postaci wielomianów z Beziera do potęgowej i odwrotnie.
 *
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#include "generic.h"
#include "pascal.h"

void to_bezier_form(int pascal[], int degree, 
                    Floating s_coeffs[], Floating r_coeffs[]) {
  // Zerujemy tablicę wynikową.
  for(int i = 0; i <= degree; ++i)
    r_coeffs[i] = 0.0;

  for(int i = 0; i <= degree; ++i) {
    // 'Zbieramy' z każdej potęgi x^n, x^n-1, ...,1 (w kolejności) 
    // współczynniki, które wynikają z dwumianu Newtona i mnożymy je przez 
    // współczynnik stojący przy potędze.
    Floating inverted_newt = 1.0 / pascal_value(pascal, degree, degree - i);

    for(int j = degree - i; j <= degree; ++j) {
      r_coeffs[degree - j] += s_coeffs[i] * inverted_newt * 
                             pascal_value(pascal, j, degree - i);
    }
  }
}

void to_exp_form(int pascal[], int degree,
                 Floating s_coeffs[], Floating r_coeffs[]) {
}
