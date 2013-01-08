/**
 * Pomocnicze definicje typów/makr/stałych i funkcji dla projektu.
 *
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#ifndef __GENERIC_H__
#define __GENERIC_H__
typedef long double Floating;

const int PASCAL_SIZE = 35;

Floating kahan_sum(Floating components[], int length);
#endif //__GENERIC_H__
