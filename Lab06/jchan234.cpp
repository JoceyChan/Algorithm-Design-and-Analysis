#include <iostream>
#include <climits>
//Resources used: Lecture/Book/Lab Session
using namespace std;

int partition(int* array, int l, int r){  
    int x = array[r];  //pivot point
    // finish
    for(int i = l; i <= r; i++){
        if(array[i] < x){
            swap(array[i], array[l]);
            l++;
        }
    }
    swap(array[r], array[l]);
    return l;
}
int rPartition(int* array, int l, int r){ 
    int moving = (r - l + 1);
    int i = rand()% moving + l;  //generater random num between left and right meaning smaller and greater
    swap(array[r], array[i]);  
    return partition(array, l, r);
}
void quicksort(int* array, int l, int r){  
    if (l < r){    
        int q = rPartition(array, l, r);
        quicksort(array, l, q-1); //sep sort left
        quicksort(array, q+1, r);  //sep sort right
    }
}
int main(){  
    // srand(time(NULL));  
    int n;  
    std::cin>>n;  
    int* array;
    array  = new int[n];  
    for(int i = 0; i < n; i++){    
        std::cin>>array[i];  
    }  
    quicksort(array, 0, n-1);  
    for(int i = 0; i < n; i++){    
        std::cout<<array[i]<<";";  
    }  
    return 0;
}


