#include <iostream>
#include <limits.h>

// Resourced Used: Lab session, Book

using namespace std;

int cut_rod(int *p, int n, int* r, int *s){  
    if(n == 0) {
        return 0;
    }
    if(r[n] >= 0) {
        return r[n];  
    }
    int q = INT_MIN;  
    for(int i = 1; i <= n; i++){    
        int ri = p[i] + cut_rod(p, n - i, r, s);    
        if (ri > q){      
            q = ri;      
            s[n] = i;    
        }  
    }  
    r[n] = q; 
    return q;
}
int main() {  
    int n;  
    cin>>n;  
    int* p = new int[n+1];  
    int* r = new int[n+1];  
    int* s = new int[n+1];  
    for(int i=1; i <= n; i++){   
        cin>>p[i];    
        r[i] = INT_MIN;    
        s[i] = INT_MIN;  
    }  
    cout<<cut_rod(p, n, r, s)<<endl;    
    // while loop to print array s; 
    while(n > 0){
        std::cout << s[n];
        std::cout << " ";
        n -= s[n];
    }  
    std::cout << "-1\n";

    return 0;
}