#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define TAM_MAX 1000

using namespace std;
using namespace std::chrono;

class StaticList {
public:
  int size;
  int list[TAM_MAX];

  // initialize list constructor
  StaticList() { size = 0; }

  // copy constructor
  StaticList(int original_list[], int tam) {
    for (int i = 0; i < tam; i++) {
      list[i] = original_list[i];
    }
    size = tam;
  }

  // change the values of 2 variables
  void swap(const int p1, const int p2) {
    int aux;
    aux = list[p1];
    list[p1] = list[p2];
    list[p2] = aux;
  }

  //receive subtree's actual size and father's node
  void heapify(int n, int i) {

    int bigger = i;
    //calculus son's index
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    
    if (l < n && list[l] > list[bigger]){
        bigger = l;
    }

    if (r < n && list[r] > list[bigger]){
        bigger = r;
    }

    if (bigger != i) {
        swap(i, bigger);
        heapify(n, bigger);
    }
  }

  void heapSort() {
    
    //loop for construct the heap
    for (int i = size / 2 - 1; i >= 0; i--){
        heapify(size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(0,i);
        print();  // print actual status of list
        heapify(i, 0);
    }

  }


  void generatePermutation(int n) {
    for (int j = 0; j < n; j++) {
      list[j] = rand() % 1000;
    }
  }

  void aleatoryList() {
    for (int i = 1; i <= TAM_MAX; i++) {

      generatePermutation(i);
      size = i;
      int vetorAux[size];
      auto start = steady_clock::now();
      heapSort();
      auto end = steady_clock::now();
      auto diff = end - start; // obtendo tempo transcorrido do algoritmo
      // cout << "Numero de elementos: " << i << " -- ";
      // cout << endl;
      // cout << "Tempo: ";
      // cout << duration<double, std::milli>(diff).count() << " ms" << endl;
      cout << duration<double, std::milli>(diff).count()
           << endl; // impressão do tempo em 'ms'
    }
  }

  // print list
  void print() {
    for (int i = 0; i < size; i++) {
      cout << list[i] << " ";
    }
    cout << endl;
  }
};

#endif