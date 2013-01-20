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
           poly2[11] = {1.0,-89948.16531000001,-2.456356317503192e9,1.9475944057289075e14,2.2761147008388884e18,5.556675039400089e21,3.2428968562701e24,3.64610409911485e26,-5.5318558175671496e28,5.0640763103490604e29,-1.071205332158518e30},
           poly3[13] = {1.0,-511.875,87317.34375,-6380403.046875,2.17359063796875e8,-3.57590717859375e9,2.8834299154375e10,-1.14429029715e11,2.22575681328e11,-2.0907304704e11,9.155887104e10,-1.717567488e10,1.073741824e9},
           poly4[21] = {1.0,-6155619.428,1.2124223093838535e13,-1.0806408800405459e19,4.796951549319206e24,-1.0612719949064219e30,1.1143065408379247e35,-4.581952900739634e39,-6.838143727629198e42,3.538035092501021e48,-1.32073397014854e52,-8.117549378902837e55,-1.0024166343780236e59,-1.6626137419279945e61,1.8801821715939992e64,-1.9200940643006375e66,6.215969607679914e67,-7.43040655398291e68,3.718386971019575e69,-6.644309735902824e69,0.0};
           zeroes1[4] = {0, 1, 2, 3},
           zeroes2[10] = {-43466.5324, -7756.431, -2353.47, -545.33229, -321.3, 3.23, 6.4325, 75.867, 54322.1129, 89983.5886},
           zeroes3[12] = {0.125, 0.25, 0.5, 1, 2, 4, 8, 16, 32, 64, 128, 256},
           zeroes4[20] = {-23033.43, -1338.223, -1337.77, -1336.98, 0, 5, 6, 7, 30.234, 65.665, 255.454, 7778.73, 54576.43, 67564.234, 127443.78, 231563.66, 544677.02, 700033, 1023664.324, 3424995.3},

           max[21];

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
  for (int i = 1; i <= 1000000; ++i) {
    to_bezier_form(pascal, 4, poly1, max);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << "De Casteljau (i == " << i << ") error: " << de_casteljau(max, 4, 
    }
    to_exp_form(pascal, 4, max, poly1);
    if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
      std::cout << "De Casteljau (i == " << i << ") error: " << horner(pascal, 4, 
    }
  }

  return 0;
}
