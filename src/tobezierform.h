/**
 * Przekształcenie z postaci potęgowej do postaci Beziera - plik nagłówkowy.
 *
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#ifndef __TOBEZIERFORM_H__
#define __TOBEZIERFORM_H__
#include "define.h"

void to_bezier_form(Floating expotential_coeffs[], 
                    Floating bezier_coeffs[], int degree);
#endif //__TOBEZIERFORM_H__
