#include <iostream>
// #include <vector>
// #include <limits.h>
#include <climits>


using namespace std;

void printOptParens(int i, int j, int n, int *brackets, int &current){
    if(i == j) {
        std::cout << "A";
        std::cout << current++;
        return;
    }
    std::cout << "(";
    printOptParens(i, *((brackets + i * n) + j), n, brackets, current);
    printOptParens(*((brackets + i * n) + j) + 1, j, n, brackets, current);
    std::cout << ")";
}
void MCO(int p[], int n){ 
    int m[n][n];
    int s[n][n];
    for(int i = 1; i < n; i++){ 
        m[i][i] = 0;
    }
    for(int l = 2; l < n; l++){
        for(int i = 1; i < n - l + 1; i++){
            int j = i + l - 1; 
            m[i][j] = INT_MAX; 
            for(int k = i; k <= j - 1; k++){
                int q = m[i][k] + m [k+1][j] + p[i-1] * p[k] * p[j];
                if( q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                } 
            } 
        }
    } 
    int j = 0; 
    std::cout << m[1][n - 1];
    std::cout << endl;
    printOptParens(1, n - 1, n, (int *)s, j);
}

int main() {  
    int n;  
    std::cin >> n;  
    int* p = new int[n+1];
    for(int i = 0; i <= n; i++){    
        std::cin >> p[i];  
    }  
    MCO(p, n + 1);
    std::cout << endl;
    return 0;
}