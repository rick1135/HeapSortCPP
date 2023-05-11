#include "ListaHeap.h"
#include <chrono>
#include <iostream>
#include <time.h>

using namespace std;

int main() {

  srand(time(NULL));
  int fixedList[] = {70, 1,  12, 8,  99, 72, 5,  15, 20, 91,
                          14, 61, 66, 41, 81, 88, 16, 21, 34, 90};

  int size = 20;

  StaticList loe(fixedList, size);
  cout << "Lista Original: " << endl;
  loe.print();
  cout << "Ordenando: " << endl;
  loe.heapSort();
  cout << "Lista Ordenada: " << endl;
  loe.print();
  cout << endl << "--------------------" << endl;

  // // Teste 2.2 - Lista aleatória
  // StaticList loe2;
  // loe2.aleatoryList();

  return 0;
}