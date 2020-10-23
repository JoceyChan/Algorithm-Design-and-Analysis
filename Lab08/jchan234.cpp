#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
// #include <math>
//resorces used Lab session and Book
using namespace std;

void insertion_sort(vector<float> bi, int n){  
    // use your code from lab00 
    //  for(int j = 1; j < n; j++){
    //     int key = bi[j];
    //     int i = j + 1; 
    //     while (i >= 0 && bi[i] < key){
    //         bi[i + 1] = bi[i];
    //         i = i - 1;
    //     }
    //     bi[i + 1] = key; 
    // }
    // print your sorted array bi separated by newline
    sort(bi.begin(),bi.end());
     for(int i = 0; i < bi.size(); i++){
        std::cout << bi[i] << endl;
    }
    // or return bi;
}
void bucket_sort(float* A, int n){    
    vector<float>* B = new vector<float>[n]; // n empty buckets   
    for(int i = 0; i < n; i++){    // putting element in buckets
        int f = (n * A[i]);    // index bucket
        B[f].push_back(A[i]);  
    }  
    for(int i = 0; i < n; i++){  // sorting individual buckets
        insertion_sort(B[i], B[i].size());  
    }  
    // you can print the result here
}
int main (){    
    int n;    
    std::cin >> n;    
    float* A = new float[n];   
    for(int i = 0; i < n; i++){        
        std::cin>>A[i];    
    }    
    bucket_sort(A, n);    
    // delete(A);    
    return 0;
}