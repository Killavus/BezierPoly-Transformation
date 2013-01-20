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

  Floating wilkinson_19th[20] = { 1,-190,16815,-920550,34916946,-973941900,20692933630,-342252511900,4465226757381,-46280647751910,381922055502195,-2503858755467550,12953636989943896,-52260903362512720,161429736530118960,-371384787345228000,610116075740491776,-668609730341153280,431565146817638400,-121645100408832000 },
           bezier_wilkinson_19th[20];

  // błąd względny: (x - obliczone x) / x

  
  // Z potęgowej do beziera.
  // pascal - tablica z trójkątem pascala
  // 19 - stopień wielomianu
  // wilkinson_19th wartości współczynników wielomianu w postaci potęgowej
  // bezier_wilkinson_19th miejsce na współczynniki w postaci beziera (tablica stopień + 1)
  to_bezier_form(pascal, 19, wilkinson_19th, bezier_wilkinson_19th);

    
  // Z beziera do potęgowej.
  // pascal - tablica z trójkątem pascala
  // 19 - stopień wielomianu
  // wilkinson_19th wartości współczynników wielomianu w postaci beziera
  // bezier_wilkinson_19th miejsce na współczynniki w postaci potęgowej (tablica stopień + 1)
  to_exp_form(pascal, 19, bezier_wilkinson_19th, wilkinson_19th);

  // Obliczanie hornerem
  // wilkinson_19th współczynniki
  // 19 - stopień
  // 1.5 - argument x do policzenia f(x)
  horner(wilkinson_19th, 19, 1.5);

  // Obliczanie de Casteljau
  // bezier_wilkinson_19th współczynniki
  // 19 - stopień
  // 1.5 - argument x do policzenia f(x)
  de_casteljau(bezier_wilkinson_19th, 19, 1.5);

  // Test 1: przekształć 1, 10, 100, 1000, 10000 razy jakieś kilka wielomianów z jednej postaci do drugiej.
  // Po każdym z tych 1, 10, 100, 1000, 10000 kroków licz wartości hornerem / de casteljau i licz błąd względny.
  //
  // Test 2: weź jakiś wielomian, weź jego współczynniki i poodejmuj np. 0.000000001 z niektórych współczynników. Policz wartości najpierw wielomianu przed odjęciem, potem po odjęciu. Potem przekształć poprawny wielomian, potem ten zaburzony i porównaj jak zmieniają się wyniki przy obliczaniu.
  return 0;
}
