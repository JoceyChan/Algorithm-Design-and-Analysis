#include <list>
#include <iostream>

using namespace std;

const int m = 13;
int hashFunction(int key, int i){
    int keyModM = ((key % 13) + (i * (1 + (key % 11))) % 13);
    // int h1 = key % 13 ;
    // int h2 = 1 + (key % 11);
    // int h = (h1 + (i * h2)) % 13;   
    return keyModM;
}
void insertion(int hashTable[m], int key){  
    // int h = hashFunction(key, i);
    for (int i = 0; i < m; i++){
        int h = hashFunction(key, i); 
        if (hashTable[h] == -1){
            hashTable[h] = key;
            break;
        }
    }
}
void deleteing(int hashTable[m], int key){  
    // int h = hashFunction(key); 
    for(int i = 0; i < m; i ++){
        if (hashTable[i] == key){
            hashTable[i] = -1; 
            break;
        }
    }
}
void searching(int hashTable[m], int key){  
    for (int i = 0; i < m; i++){
        int h = hashFunction(key, i);
        if (hashTable[i] == key){
            std::cout << i << endl;
            break; 
        }
        else if (i == 12 && hashTable[i] != key){
            std::cout << "NOT_FOUND" << endl;
        }        
    }
}
int main() {  
    int key;  
    // int i;
    // Create Hash Table  
    int hashTable[m];  
    // Initialize Hash Table  
    for(int i=0; i < m; i++) {    
        hashTable[i] = -1;  
    }    
    // KEY INSERTION  
    std::cin >> key;  
    while(key != -1) {    
        // 1. calculate hash function    
        // int h = hashFunction(key, i);    
        // 2. put it into your hash table    
        insertion(hashTable, key); 
        std::cin >> key; 
    }  
    // ++++table printout++++  
    std::cout << "++++table printout++++" << endl; 
    for(int i = 0; i < m; i++){    
        if(hashTable[i] >= 0){
            std::cout << hashTable[i] << endl;    
        }    
        else{      
            std::cout << endl;    
        }  
    }  
    std::cout << "++++searching++++"<<endl;  
    // KEY SEARCHING  
    std::cin >> key;  
    while(key != -2) {    
        // 1. calculate hash function    
        // int h = hashFunction(key, i);    
        // 2. search that key in your hash table, print either index or a message "NOT FOUND"    
        searching(hashTable, key);        
        std::cin >> key;  

    }  
    std::cout << "++++deleting++++"<<endl;  
    // KEY DELETING  
    std::cin >> key;  
    while(key != -3) {    
        // 1. calculate hash function 
        // int h = hashFunction(key, i);        
        // 2. delete a key from your hash table    
        deleteing(hashTable, key);
        std::cin >> key;

    }  
        // ++++table printout++++  
    cout << "++++table printout++++"<<endl;  
    for(int i = 0; i < m; i++){    
        if(hashTable[i] >= 0){      
            std::cout << hashTable[i] << endl;    
        }    
        else{      
            std::cout << endl;    
        }  
    }
    return 0;

}