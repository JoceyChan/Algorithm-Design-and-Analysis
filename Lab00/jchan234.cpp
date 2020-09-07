#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // ofstream file;
    // file.open ("o1.txt", ios::ate);
    // std::cin.get();
    // return 0;
    int input[7] = {6, 15, 13, 12, 11, 16, 14};

    for(int i = 0; i < 7; i++){
        std::cout << input[i] << std::endl;
    }
    return 0;
}