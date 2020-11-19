#include<iostream>
#include<climits>

//resources used Textbook

using namespace std;

void bottomUpCutRod(int *p, int n){
    int len = n + 1;
    int r[len];
    int s[len];
    r[0] = 0;

    int j, i;
    for(j = 1; j <= n; j++){
        int q = INT_MIN;
        for(i = 1; i <= j; i++) {
            if(q < p[i - 1] + r[j - i]){
                q = p[i - 1] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    std::cout << r[n];
    std::cout << endl;
    while(n > 0){
        std::cout << s[n];
        std::cout << " ";
        n -= s[n];
    }
}
int main(){
    int n;
    std::cin >> n;
    int p[n];

    for(int i = 0; i < n; i++){
        std::cin >> p[i];
    }
    bottomUpCutRod(p, n);
    std::cout << "-1\n";
}