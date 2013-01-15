/**
 * Pomocnicze definicje typów/makr/stałych i funkcji dla projektu.
 *
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#include "generic.h"
#include <iostream>

/**
 * Patrz sprawozdanie w celu poznania odpowiedzi "jak to zostało stworzone"
 **/
Floating reduction_bezier_binomial(int n, int i, int j) {
  Floating result = 1.0;

  for(Floating k = n-i+1; k <= n; k += 1.0)
    result *= (k - n + j) / k; 

  return result;
}

Floating reduction_expotential_binomial(int j, int i, int n, int k) {

}


