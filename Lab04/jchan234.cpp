#include <stdio.h>
#include <iostream>
//Resources used: Lecture/Book/Lab Session
using namespace std;

int max_crossing(int* array, int low, int mid, int high){
    int left_sum = INT_MIN;
    int sum = 0; 
    //finish..
    int right_sum = INT_MIN;
    int sum = 0; 
    //finish..
    
    return left_sum + right_sum;
}
int max_subarray(int* array, int low, int high){
    if(low == high){
        return array[low];
    }
    int mid = (low +high) /2;
    int left_sum = max_subarray(array, low, mid);
    int right_sum = max_subarray(array, mid+1, high);
    int cross_sum = max_crossing(array, low, mid, high);
    if(left_sum >= right_sum && left_sum >= max_crossing){
        return left_sum;
    }
    //finish..
}

int main(){
    int n;
    cin >> n;
    int* array;
    array = new int[n];
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    int max_sum = max_subarray(array, 0, n-1); //maybe just n not n-1
    std::cout << max_sum;

    return 0;
}