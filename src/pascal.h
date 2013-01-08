/**
 * Preprocessing - obliczanie wartości dwumianu Newtona - plik nagłówkowy.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#ifndef __PASCAL_H__
#define __PASCAL_H__
#include "define.h"

void pascal_populate(int result_table[]);
int pascal_value(int results[], int row, int col);
#endif //__PASCAL_H__
