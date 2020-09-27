#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Resources used: Lecture/Book/Lab Session
using namespace std;

void mergeHelper(int i, int j, int k, int n1, int n2, int* array, int* Left, int* Right){
    while (i < n1 && j < n2){
        if(Left[i] <= Right[j]){
            array[k] = Left[i];
            i++;
        }
        else{
            array[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        array[k] = Left[i];
        i++;
        k++;
    }
    while(j < n2){
        array[k] = Right[j];
        j++;
        k++;
    }
}
void mergeFn(int* array, int p, int middle, int r){
  
    int n1 = middle - p + 1;
    int n2 = r - middle;
    int Left[n1];
    int Right[n2];
   
    for(int j = 0; j < n2; j++){
        Right[j] = array[middle + 1 + j];
    }
    for(int i = 0; i < n1; i++){
        Left[i] = array[p + i];
    }
    
    int i = 0;
    int j = 0;
    int k = p;
    mergeHelper(i, j, k, n1, n2, array, Left, Right);
}
void mergeSortFn(int* array, int p, int r){
    if(p < r){
        int middle = (p + r)/2;
        mergeSortFn(array, p, middle);
        mergeSortFn(array, middle + 1, r);
        mergeFn(array, p, middle, r);
    }
}
int main(){
    int arrayLength;
    std::cin >> arrayLength;
    int* array;
    array = new int[arrayLength];
    int p = 0;
    int r = arrayLength;


    for(int i = 0; i < arrayLength; i++){
        std::cin >> array[i];
    }
    mergeSortFn(array, p, r - 1);

    for(int i = 0; i < arrayLength; i++){
        std::cout << array[i] << ";";
    }
    return 0;
}