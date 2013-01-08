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

/** Algorytm sumacyjny Kahana - bazując na: 
 * http://pl.wikipedia.org/wiki/Algorytm_sumacyjny_Kahana
 **/
Floating kahan_sum(Floating components[], int length) {
  Floating sum;
  if(length == 0) 
    sum = 0.0;
  else {
    sum = components[0];
    Floating correction = 0.0, component_sub;

    for(int i = 1; i < length; ++i) {
      component_sub = components[i] - correction;
      correction = ((sum + component_sub) - sum) - component_sub;
      sum += component_sub;
    }
  }

  return sum;
}
