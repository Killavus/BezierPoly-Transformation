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

/**
 * Skrócenie z odwróconym symbolem Newtona przy przekształceniu Beziera.
 **/
Floating reduction_bezier_binomial(int n, int i, int j);

/**
 * Skrócenie z drugim symbolem Newtona w przekształceniu potęgowym.
 **/
Floating reduction_expotential_binomial(Floating j, Floating i, Floating n, Floating k);
#endif //__GENERIC_H__
