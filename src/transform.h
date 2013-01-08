/**
 * Przekształcenia postaci wielomianów z Beziera do potęgowej i odwrotnie.
 *
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__
#include "generic.h"

void to_bezier_form(int pascal[], int degree, 
                    Floating s_coeffs[], Floating r_coeffs[]);

void to_exp_form(int pascal[], int degree,
                 Floating s_coeffs[], Floating r_coeffs[]);
#endif //__TRANSFORM_H__
