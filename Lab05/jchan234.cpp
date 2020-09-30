#include <stdio.h>
#include <iostream>
//Resources used: Lecture/Book/Lab Session
using namespace std;

void max_heapify(int* a, int i, int heapSize){
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = 0;
    if(l <= heapSize && a[1] > a[i]){
        largest = l;

    }
    else{
        largest = i;
    }
    if(largest != i){
        swap(a[i], a[largest]);
        max_heapify(a, largest, heapSize);
    }
}

void buildHeap(int* a, int n){
    int heapSize = n;
    //finsih
}

void heapsort(int* a, int n){
    buildHeap(a, n);
    int heapSize = n;
    for(int i = n; i > 1; i--){
        int temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        heapSize--;
        max_heapify(a, 1, heapSize);
    }
}

int main(){
    int n = 0;
    std::cin >> n;
    int* array;
    array = new int[n+1];
    for(int i = 1; i <= n; i++){
        std::cin >> array[i];
    }
    heapsort(array, n);

    for(int i = 1; i <= n; i++){
        std::cout << array[i] << ";";
    }
}