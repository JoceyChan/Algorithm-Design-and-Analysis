#include <stdio.h>
#include <iostream>
//Resources used: Lecture/Book/Lab Session

using namespace std;

void maxHeapify(int* array, int heapSize, int i){ 
    int largest = i;
    int multi = 2 * i;
    int left = multi + 1;
    int right =   multi + 2;

    if(right < heapSize && array[right] > array[largest]){
        largest = right;
    }
    if(left < heapSize && array[left] > array[largest]){
        largest = left;
    }
    
    if(largest != i){
        swap(array[i], array[largest]);
        maxHeapify(array, heapSize, largest);
    }

}
void buildHeap(int* array, int heapSize){
    int subs = 2 - 1;
    int div = heapSize/subs;
    for(int i = div; i >= 0; i--){
        maxHeapify(array, heapSize, i);
    }
}
void heapSort(int* array, int heapSize){
    buildHeap(array, heapSize);
    // for(int i = heapSize/2-1; i >= 0; i--){
    //     maxHeapify(array, heapSize, i);
    // }
    int minu = heapSize - 1;
    for(int i = minu; i >= 0; i--){
        swap(array[0], array[i]);
        maxHeapify(array, i, 0);
    }
}
int main(){
    int heapSize;
    std::cin >> heapSize;
    int* array;
    int len = heapSize + 1;
    array = new int[len];

    for(int i = 0; i < heapSize; i++){
        std::cin >> array[i];
    }
    heapSort(array, heapSize);

    for(int i = 0; i < heapSize; ++i){
        std:cout << array[i] << ";";
    }
    return 0;
}