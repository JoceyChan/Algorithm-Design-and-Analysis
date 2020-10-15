#include "iostream"
#include <vector>


using namespace std;
// for i = 1 to d --> use countingSort to sort array A tto digit i
vector<vector<int>> countingSort(vector<vector<int>> A, int sigIndex, int n){  
    // count all the items
    int counts[10]; 
    // first for loop here... 
    for(int i = 0; i < 10; i++){
        counts[i] = 0;
    }

    // second for loop here:  
    for(int j = 1; j < n; j++){    
        counts[A[j][sigIndex]]++; 
        // std::cout << counts[A[j][sigIndex]] << "," << A[j][sigIndex] << ";" << endl;  
    }
    // third for loop here...
    for(int i = 1; i < 10; i++){
        counts[i] += counts[i-1]; //cummulative sum
    }
    vector<vector<int>> B = A;   
    // the last for loop 
    for(int j = n - 1; j >= 0; j--){
        B[counts[A[j][sigIndex]]-1] = A[j];
        counts[A[j][sigIndex]]--;
    }
     return B;
}
    
vector<vector<int>> radix_sort(vector<vector<int>> A, int n){  
    int k = 9;  
    vector<vector<int>> B = A;  
    for(int i = k; i >= 0; i--){  
        B = countingSort(B, i, n); 
        // std::cout << i << ";" << endl;  
    }
    // std::cout << "made it this far" << ";"; 
    // exit (EXIT_FAILURE);  
    return B;
}
int main() {    
    int arraySize;    
    std::cin >> arraySize;
    vector<vector<int>> Sequence;        
    for (int i = 0; i < arraySize;i++){        
        vector<int> row;        
        for (int j = 0; j < 10;j++){    
            int value;            
            std::cin>>value;
            row.push_back(value); //values added to array    
        }        
        Sequence.push_back(row);    
    }

    vector<vector<int>> sorted = radix_sort(Sequence, arraySize); 
    //print out sorted array 
    for(int i = 0; i < sorted.size() - 1; i++){
        for(int j = 0; j < 10; j++){
            std::cout << sorted[i][j] << ";";
        }
        std::cout << endl;
    }
    return 0;
}