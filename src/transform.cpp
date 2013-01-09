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
  for(int i = 0; i <= degree; ++i)
    r_coeffs[i] = 0.0;

  for(int i = 0; i <= degree; ++i) {
    Floating inverted_newt = 1.0 / pascal_value(pascal, degree, degree - i);

    for(int j = degree - i; j <= degree; ++j)
      r_coeffs[degree - j] += s_coeffs[i] * inverted_newt * 
                             pascal_value(pascal, j, degree - i);
  }
}

void to_exp_form(int pascal[], int degree,
                 Floating s_coeffs[], Floating r_coeffs[]) {
  for(int i = 0; i <= degree; ++i)
    r_coeffs[i] = 0.0;

  for(int i = 0; i <= degree; ++i) {
    for(int k = degree - i; k <= degree; ++k) {
      int sign = 1;
      if(((degree - i) + k) % 2 == 1)
        sign = (-1);

      r_coeffs[degree - k] += sign * pascal_value(pascal, k, degree - i) * 
                              pascal_value(pascal, degree, k) * s_coeffs[i];
    }
  }
}
