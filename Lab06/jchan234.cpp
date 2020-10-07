#include <stdio.h>
#include <iostream>
#include <time.h>
//Resources used: Lecture/Book/Lab Session
using namespace std;

int partition(int* A, int p, int r){  
    int x = A[r];  
    // finish
}
int rpartition(int* A, int p, int r){  
    int i = rand()%(r - p + 1) + p;  
    swap(A[r], A[i]);  
    return partition(A, p, r);
}
void quicksort(int* A, int p, int r){  
    if (p < r){    
        int q = rpartition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, p);  
    }
}
int main(){  
    srand(time(NULL));  
    int n = 0;  
    cin>>n;  
    int* arr = new int[n];  
    for(int i = 0; i < n; i++){    
        cin>>arr[i];  
    }  
    quicksort(arr, 0, n-1);  
    for(int i = 0; i < n; i++){    
        cout<<arr[i]<<";";  
    }  
    return 0;
}


