#include <iostream>
#include <vector>
// Resources used: Book/ Lab session/office hours
using namespace std;
// for i = 1 to d --> use countingSort to sort array A tto digit i
vector<vector<int>> countingSort(vector<vector<int>> A, int sigIndex, int n){  
    // count all the items
    int counts[10]; 
    vector<vector<int>> B = A;   
    // first for loop here... 
    for(int i = 0; i < 10; i++){
        counts[i] = 0; //initiates array to all 0
    }
    // second for loop here:  
    for(int j = 0; j < n; j++){    
        counts[A[j][sigIndex]]++; //inspects each input element
        // std::cout << counts[A[j][sigIndex]] << "," << A[j][sigIndex] << ";" << endl;  
    }
    // third for loop here...
    for(int i = 1; i < 10; i++){
        counts[i] += counts[i-1]; //cummulative sum //determine hoe many input elements are <= to i  by running sum of array counts
    }
    // the last for loop 
    for(int j = n - 1; j >= 0; j--){
        B[counts[A[j][sigIndex]]-1] = A[j]; //places elements in A[j] into its correct sorted position in ouput array B
        counts[A[j][sigIndex]]--; // Decrementting counts[a[j]] makes the next input element with a value = to A[j]
    }
     return B;
}
    
vector<vector<int>> radix_sort(vector<vector<int>> A, int n){  
    int k = 9;  
 
    for(int i = k; i >= 0; i--){  
        A = countingSort(A, i, n); 
        // std::cout << i << ";" << endl;  
    }
    // std::cout << "made it this far" << ";"; 
    // exit (EXIT_FAILURE);  
    return A;
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
    for(int i = 0; i < sorted.size(); i++){
        for(int j = 0; j < 10; j++){
            std::cout << sorted[i][j] << ";";
        }
        std::cout << endl;
    }
    return 0;
}