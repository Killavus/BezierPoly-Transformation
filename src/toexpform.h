/**
 * Przekształcenia z postaci Beziera do postaci potęgowej.
 *
 * Pracownia P3.11.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#ifndef __TOEXPFORM_H__
#define __TOEXPFORM_H__
#include "define.h"

void to_exp_form(Floating bezier_coeffs[] /* an, an-1, ..., a0 */,
                 Floating expotential_coeffs[], int degree);
#endif //__TOEXPFORM_H__
