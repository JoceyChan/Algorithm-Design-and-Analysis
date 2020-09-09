#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void insertionSorted(int n, int* arr){
    for(int j = 1; j < n; j++){
        int key = arr[j];
        int i = j - 1; 
        while (i >= 0 && arr[i] < key){
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key; 
    }
    for(int k = 0; k < n; k++){
        std::cout << arr[k] << ";";
    }
}

int main() {
    int n;
    cin >> n;
    // cout << n;
    int* arr = new int[n];
    // cin >> arr;
    // cout << arr;
    // std::cout << "1" << ";";
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    insertionSorted(n, arr);

}
