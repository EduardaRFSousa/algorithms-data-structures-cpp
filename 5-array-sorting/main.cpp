#include <iostream>
#include <chrono>

#include "ordenacao.h"

int main() {
    int size = 10000;
    bool print = false;

    vector<int> array(size);

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (size * 2);
    }

    test(array, "BubbleSort   ", bubblesort, print);
    test(array, "SelectionSort", selectionsort, print);
    test(array, "InsertionSort", insertionsort, print);
    test(array, "MergeSort    ", mergesort, print);
    test(array, "QuickSort    ", quicksort, print);
}