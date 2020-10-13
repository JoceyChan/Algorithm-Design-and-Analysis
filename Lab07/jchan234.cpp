#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> counting_sort(vector<vector<int>> A, int c, int n){  
    int counts[10] = {0};  
    // first for loop here... 
    vector<vector<int>> arr[c];  //output array of vector 
    vector<vector<int>>* results = new vector<vector<int>>[c];       

    for(int i = 0; i < c; i++){
        counts[A[i][n]%10]++;  
    }
    // second for loop here:  
    for(int j=1; j < 10; j++){    
        counts[j] += counts[j-1];
    }  
    // third for loop here...
    for(int z = c - 1; z >= 0; z--){    
        results[counts[A[z][n]%10]-1] = A[z];
    }   
    // the last for loop 
    for(int a = 0; a < c; a++){
            A[a] = results[a];
        } 
    vector<vector<int>> B = A;   
    return B;
}
    
vector<vector<int>> radix_sort(vector<vector<int>> A, int n){  
    int k = 9;  
    vector<vector<int>> B = A;  
    for(int i = k; i >= 0; i--){   
        B = counting_sort(B, i, n);  
    }  
    return B;
}
int main (){    
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
    for(int i = 0; i < arraySize; i++){
        for(vector<int>::iterator output = A[i].begin(); output != A[i].end(); output++){
            cout << *output << ";";
        }
    }
return 0;
}