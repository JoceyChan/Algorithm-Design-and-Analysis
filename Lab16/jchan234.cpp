#include <iostream>
#include <vector>
#include <limits.h>
#include <utility>
#include <queue>

//resources used: Book, Lab sessions, previous labs like BFS and lab 14

using namespace std;

typedef pair<int, int> iPair;//integer pair

int main() {  
    int n;  
    cin >> n; 
    int m; 
    cin >> m;  

    vector<iPair> G[n];
    int num = 999999999;
    
    for(int i = 0; i < m; i++){    
        int u,v,w;    
        cin>>u>>v>>w;    
        pair<int,int> p1(v,w);    
        pair<int,int> p2(u,w);    
        G[u].push_back(p1);    
        G[v].push_back(p2);  
    }  
    priority_queue<iPair, vector<iPair>, greater<iPair>> Q; //pseudocode from book and lab pdf
    Q.push(pair<int, int>(0,0)); //inseting into queue
    
    int parent[n];
    int k[n]; //key

    for(int i = 0; i < n; i++) {
        k[i] = num; 
        parent[i] = 0;  
    }

    bool seen[n];
    while(!Q.empty()){ // Q != 0
       int u = Q.top().second;   //extract min
        Q.pop();
        seen[u] = true;
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].first;
            int weight = G[u][i].second;
            if(!seen[v] && weight < k[v]) {
                k[v] = G[u][i].second;
                Q.push(pair<int,int>(weight,v));
                parent[v] = u;
            }
        } 
    }
    for(int i = 1; i < n; i++){ // print array parents starting from 1
        cout << parent[i];
        cout << endl;
    }    
    return 0;    
}