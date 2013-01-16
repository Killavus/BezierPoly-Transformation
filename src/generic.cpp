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
 * Redukcja problemu obliczania (n po i)^(-1) * (j po i), 
 * aby zmniejszyć wyniki pośrednie.
 *
 * Proces przekształcenia tego wzoru jest przedstawiony w sprawozdaniu.
 **/
Floating reduction_bezier_binomial(int n, int i, int j) {
  Floating result = 1.0;

  for(Floating k = n-i+1; k <= n; k += 1.0)
    result *= (k - n + j) / k; 

  return result;
}
