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

  Floating poly1[5] = {1,-6,11,-6,0},
           poly2[11] = {2,-31,44,204,13,-287,159,60,-29,-48,144},
           poly3[13] = {-3,-8,7,4,-40,-60,-54,-18,109,0,-2,29,24},
           poly4[21] = {-7,62,-79,16,-97,-4,-11,28,25,-193,285,-226,13,-6,-7,-15,-51,168,-26,4,-16},
           max[21];
  
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

  // Test 1: przekształć 1, 10, 100, 1000, 10000 razy jakieś kilka wielomianów z jednej postaci do drugiej.
  // Po każdym z tych 1, 10, 100, 1000, 10000 kroków licz wartości hornerem / de casteljau i licz błąd względny.
  //
  // Test 2: weź jakiś wielomian, weź jego współczynniki i poodejmuj np. 0.000000001 z niektórych współczynników. Policz wartości najpierw wielomianu przed odjęciem, potem po odjęciu. Potem przekształć poprawny wielomian, potem ten zaburzony i porównaj jak zmieniają się wyniki przy obliczaniu.
  std::cout << "POLY1 test:" << std::endl;
  for (int i = 1; i <= 1000000; ++i) {
    to_bezier_form(pascal, 4, poly1, max);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << "De Casteljau (i == " << i << ") error: " << de_casteljau(max, 4, 3) << std::endl;
    }
    to_exp_form(pascal, 4, max, poly1);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << "Horner (i == " << i << ") error: " << horner(poly1, 4, 3) << std::endl;
    }
  }

  std::cout << "POLY2 test:" << std::endl;
  for (int i = 1; i <= 1000000; ++i) {
    to_bezier_form(pascal, 10, poly2, max);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << "De Casteljau (i == " << i << ") error: " << de_casteljau(max, 10, 4) << std::endl;
    }
    to_exp_form(pascal, 10, max, poly2);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << "Horner (i == " << i << ") error: " << horner(poly2, 10, 4) << std::endl;
    }
  }

  std::cout << "POLY3 test:" << std::endl;
  for (int i = 1; i <= 1000000; ++i) {
    to_bezier_form(pascal, 12, poly3, max);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << "De Casteljau (i == " << i << ") error: " << de_casteljau(max, 12, -3) << std::endl;
    }
    to_exp_form(pascal, 12, max, poly3);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << "Horner (i == " << i << ") error: " << horner(poly3, 12, -3) << std::endl;
    }
  }

  std::cout << "POLY4 test:" << std::endl;
  for (int i = 1; i <= 1000000; ++i) {
    to_bezier_form(pascal, 20, poly4, max);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << "De Casteljau (i == " << i << ") error: " << de_casteljau(max, 20, 2) << std::endl;
    }
    to_exp_form(pascal, 20, max, poly4);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << "Horner (i == " << i << ") error: " << horner(poly4, 20, 2) << std::endl;
    }
  }

  return 0;
}
