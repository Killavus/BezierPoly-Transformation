/**
 * Preprocessing - obliczanie wartości dwumianu Newtona.
 *
 * Autorzy: Marcin Grzywaczewski, Szymon Koper
 * Instytut Informatyki Uniwersytetu Wrocławskiego
 * Wrocław, 2013
 **/
#include <iostream>

#include "define.h"

static int PAS_POS(int row, int col) { 
  return row * PASCAL_SIZE + (col % PASCAL_SIZE); 
}

void pascal_populate(int result_table[]) {
  result_table[PAS_POS(0, 0)] = 1;
  result_table[PAS_POS(1, 0)] = 1;
  result_table[PAS_POS(1, 1)] = 1;

  for(int row = 2; row < PASCAL_SIZE; ++row) {
    result_table[PAS_POS(row, 0)] = 1;
    result_table[PAS_POS(row, row)] = 1;
    for(int col = 1; col < row; ++col)
      result_table[PAS_POS(row, col)] = result_table[PAS_POS(row-1, col)] + result_table[PAS_POS(row-1, col-1)];
  }

  for(int i = 0; i < PASCAL_SIZE; ++i) {
    for(int j = 0; j <= i; ++j) {
      std::cout << result_table[PAS_POS(i, j)] << " ";
    }
    std::cout << std::endl;
  }
}

int pascal_value(int results[], int row, int col) {
  return results[PAS_POS(row, col)];
}
