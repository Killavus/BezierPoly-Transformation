/**
 * Preprocessing - obliczanie wartości dwumianu Newtona - plik nagłówkowy.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#ifndef __PASCAL_H__
#define __PASCAL_H__
#include "generic.h"

void pascal_populate(Floating result_table[]);
Floating pascal_value(Floating results[], int row, int col);
#endif //__PASCAL_H__
