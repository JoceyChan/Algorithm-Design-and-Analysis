#include <stdio.h>
#include <iostream>

using namespace std;
int linearSearchFn(int nSize, int aOfS, int* array){
    for(int i = 0; i < nSize; i++){
        if(array[i] == aOfS){
            std::cout << i;
            return i;
            break;
        }
    }
    std::cout << -1;
    return -1; 
}
int main(){
    int nSize;
    int aOfS;
    std::cin >> nSize;
    std::cin >> aOfS;

    int* array;
    array = new int[nSize];
    for(int i = 0; i < nSize; i++){
        int aI;
        std::cin >> aI;
        array[i] = aI;
    }
    // std::cout << "45";
    linearSearchFn(nSize, aOfS, array);
}