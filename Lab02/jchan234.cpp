#include <stdio.h>
#include <iostream>

using namespace std;
//Resources used: Book, Lecture, Lab Sessions and Lab guidelines

int binarySearchFn(int nSize, int aOfS, int* array){
//     // std::cout << 22;
    int l = 0;
    int r = nSize - 1;
    while(l < r || l == r){
        int half = (l + r) / 2;
        if(array[half] == aOfS){
            std::cout << half;
            return half;
        }
        else if(array[half] > aOfS){
            r = half - 1;
        }
        else{
            l = half + 1;
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
    // return -1;
    binarySearchFn(nSize, aOfS, array);
    return 0;
}