#include <stdio.h>
#include <iostream>
//Resources used: Lecture/Book/Lab Session
using namespace std;
void maxHeapify(int* array, int heapSize, int i){ 
    int largest = i;
    int left = 2 * i + 1;
    int right =  2 * i + 2;

    if(left < heapSize && array[left] > array[largest]){
        largest = left;
    }
    if(right < heapSize && array[right] > array[largest]){
        largest = right;
    }
    if(largest != i){
        swap(array[i], array[largest]);
        maxHeapify(array, heapSize, largest);
    }

}
// void buildHeap(int* array, int heapSize){
//     for(int i = heapSize/2; i >= 1; i--){
//         maxHeapify(array, heapSize, i);
//     }
// }
void heapSort(int* array, int heapSize){
    // buildHeap(array, heapSize);
    for(int i = heapSize/2-1; i >= 0; i--){
        maxHeapify(array, heapSize, i);
    }
    for(int i = heapSize-1; i >= 0; i--){
        swap(array[0], array[i]);
        maxHeapify(array, i, 0);
    }
}
int main(){
    int heapSize;
    std::cin >> heapSize;
    int* array;
    array = new int[heapSize+1];

    for(int i = 0; i < heapSize; i++){
        std::cin >> array[i];
    }
    heapSort(array, heapSize);

    for(int i = 0; i < heapSize; ++i){
        std:cout << array[i] << ";";
    }
    return 0;
}