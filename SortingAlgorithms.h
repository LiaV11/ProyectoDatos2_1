#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include "DoublyLinkedList.h"

template <typename T>
void bubbleSort(DoublyLinkedList<T>& list) {
    bool swapped;
    int n = list.getSize();
    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (list[i - 1] > list[i]) {
                list.swap(i - 1, i);
                swapped = true;
            }
        }
    } while (swapped);
}

template <typename T>
int partition(DoublyLinkedList<T>& list, int low, int high) {
    T pivot = list[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (list[j] <= pivot) {
            i++;
            list.swap(i, j);
        }
    }
    list.swap(i + 1, high);
    return i + 1;
}

template <typename T>
void quickSort(DoublyLinkedList<T>& list, int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

#endif // SORTINGALGORITHMS_H
