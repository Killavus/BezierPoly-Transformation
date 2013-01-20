/**
 * Metody obliczania wartości wielomianów - de Casteljau, 
 * oraz schemat Hornera.
 *
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#ifndef __COMPUTATION_H__
#define __COMPUTATION_H__
#include "generic.h"

Floating horner(Floating coefficients[], int degree, Floating arg);
Floating de_casteljau(Floating coefficients[], int degree, Floating arg);
#endif //__COMPUTATION_H__

