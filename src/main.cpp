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

void print_bezier_form(std::string title, Floating coeffs[], int degree) {
  std::cout << "Polynomial " << title << " in Bezier form (degree " << degree
    << ")" << std::endl;
  std::cout.precision(5);
  for(int i = 0; i <= degree; ++i)
    std::cout << "b" << (degree - i) << ": " << coeffs[i] << " ";
  std::cout << std::endl;
}

void print_exp_form(std::string title, Floating coeffs[], int degree) {
  std::cout << "Polynomial " << title << " in expotential form (degree " << degree
    << ")" << std::endl;
  std::cout.precision(5);
  for(int i = 0; i <= degree; ++i)
    std::cout << "a" << (degree - i) << ": " << coeffs[i] << " ";
  std::cout << std::endl;
}

void print_comparison(std::string poly_title, Floating arg, Floating bez_coeffs[],
                      Floating exp_coeffs[], int degree, Floating real_val) {
  std::cout << std::endl << "===================================" << std::endl;
  std::cout << "Comparison of value computing using Horner and de Casteljau"
            << std::endl;

  print_bezier_form(poly_title, bez_coeffs, degree);
  print_exp_form(poly_title, exp_coeffs, degree);

  std::cout << "COMPUTING VALUE AT ARGUMENT " << arg << std::endl;

  Floating de_casteljau_result = de_casteljau(bez_coeffs, degree, arg),
           horner_result = horner(exp_coeffs, degree, arg);

  std::cout.precision(32);
  std::cout << "Horner scheme: " << horner_result << std::endl;
  std::cout << "De Casteljau algorithm: " << de_casteljau_result << std::endl;
  std::cout << "Real value: " << real_val << std::endl;
  std::cout << "===================================" << std::endl;
}

int main(void) {
  pascal_populate(pascal);

  // Some examples:
  Floating exp_coeff_9tsheby[10] = { 256.0, 0.0, -576.0, 0.0, 432.0, 0.0,
                                    -120.0, 0.0, 9.0, 0.0 },
           bez_handwritten[3] = { 7.0, 3.5, 2.0 },
           exp_handwritten[3],
           bez_coeff_9tsheby[10];

  to_bezier_form(pascal, 9, exp_coeff_9tsheby, bez_coeff_9tsheby);
  to_exp_form(pascal, 2, bez_handwritten, exp_handwritten);

  print_comparison("handwritten example", 0.5, bez_handwritten, 
                   exp_handwritten, 2, 4.00000);
  print_comparison("handwritten example", 0.75, bez_handwritten,
                   exp_handwritten, 2, 5.37500);
  print_comparison("handwritten example", 1.0, bez_handwritten,
                   exp_handwritten, 2, 7);
  print_comparison("handwritten example", 0.7823411, bez_handwritten,
                   exp_handwritten, 2, 5.57113849349842);

  print_comparison("9th Tshebyshew polynomial", 0.13, bez_coeff_9tsheby, 
                   exp_coeff_9tsheby, 9, 0.922041);
  print_comparison("9th Tshebyshew polynomial", 0.17, bez_coeff_9tsheby, 
                   exp_coeff_9tsheby, 9, 0.922041);
  print_comparison("9th Tshebyshew polynomial", -0.866025, bez_coeff_9tsheby, 
                   exp_coeff_9tsheby, 9, 0.0);

  return 0;
}
