#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
// Resources I used to know how to retrieve n and the arr: 
// http://www.cplusplus.com/doc/tutorial/basic_io/
// http://www.cplusplus.com/doc/tutorial/files/
// https://wwwx.cs.unc.edu/~sparkst/howto/cpp_main.php
// and book/Lecture/TA, I used the book and lecture to understand how Insertion functions 
// Got help from peer Betsy to understand that we do not have to open the testfiles in our .cpp file
void insertionSortedFn(int n, int* arr){ 
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
    std::cin >> n;

    int* arr;
    arr = new int[n];

    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    insertionSortedFn(n, arr);

}
