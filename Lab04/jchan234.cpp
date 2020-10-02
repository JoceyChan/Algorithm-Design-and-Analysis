#include <stdio.h>
#include <iostream>
//Resources used: Lecture/Book/Lab Session
using namespace std;

int maxCrossingFn(int* array, int low, int mid, int high){
    int rightSum = INT_MIN;
    int sum2 = 0; 
    //Finish..
    int cond2 = high + 1;
    for(int j = mid + 1; j < cond2; ++j){
        sum2 += array[j];
        if(sum2 > rightSum){
            rightSum = sum2;
            int maxRight = j;
        }
    }
    int leftSum = INT_MIN;
    int sum = 0; 
    int cond = low - 1; 
    //finish..
    for(int i = mid; i > cond; --i){
        sum += array[i];
        if(sum > leftSum){
            leftSum = sum;
            int maxLeft = i; 
        }
    }
    
    return leftSum + rightSum;
}

// int maxHelper(int* array, int low, int high, int sumL, int mid, int leftSum , int rightSum, int crossSum){
//     if(leftSum >= rightSum && leftSum >= crossSum){
//         return leftSum;
//     }
//     else if( crossSum <= rightSum && leftSum <= rightSum){
//         return rightSum;
//     }
//     else{
//         return crossSum;
//     }
// }

int maxSubarray(int* array, int low, int high){
    if(low == high){
        return array[low];
    }
    int sumL = (low + high);
    int mid = sumL /2;
    int leftSum = maxSubarray(array, low, mid);
    int rightSum = maxSubarray(array, mid+1, high);
    int crossSum = maxCrossingFn(array, low, mid, high);
    
    
    if(crossSum <= rightSum && leftSum <= rightSum){
        return rightSum;
    }
    else if(leftSum >= rightSum && leftSum >= crossSum){
        return leftSum;
    }
    else{
        return crossSum;
    }
}

int main(){
    int nSize;
    std::cin >> nSize;
    int* array;
    array = new int[nSize];
    for(int i = 0; i < nSize; i++){
        std::cin >> array[i];
    }
    int length = nSize-1;
    int max_sum = maxSubarray(array, 0, length); //maybe just n not n-1
    std::cout << max_sum;

    return 0;
}