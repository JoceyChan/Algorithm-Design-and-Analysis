#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Resources used: Lecture/Book/Lab Session/peer: Alberto V. - helped explain the process of merge sort 
using namespace std;

void mergeHelper(int a, int b, int c, int n1, int n2, int* array, int* left, int* right){
    while (a < n1 && b < n2){
        if(left[a] <= right[b]){
            array[c] = left[a];
            a++;
        }
        else{
            array[c] = right[b];
            b++;
        }
        c++;
    }
    while (a < n1){
        array[c] = left[a];
        a++;
        c++;
    }
    while(b < n2){
        array[c] = right[b];
        b++;
        c++;
    }
}
void mergeFn(int* array, int p, int middle, int r){
  
    int n1 = middle - p + 1;
    int n2 = r - middle;
    int left[n1];
    int right[n2];
   
    for(int j = 0; j < n2; j++){
        right[j] = array[middle + 1 + j];
    }
    for(int i = 0; i < n1; i++){
        left[i] = array[p + i];
    }
    
    int a = 0;
    int b = 0;
    int c = p;
    mergeHelper(a, b, c, n1, n2, array, left, right);
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