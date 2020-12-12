#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <climits>

//Resources used: Book/ Lab session
using namespace std;

struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void AddEdge(string,string,int);
    void AddVertex(string);    
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}
void Graph::AddVertex(string vert) {    
    vertices.push_back(vert);
}

void Graph::AddEdge(string vert1,string vert2,int weight) {
    if(FindVertex(vert1) && FindVertex(vert2)){
        pair<string,string> p(vert1, vert2);    
        edges[p] = weight;
    }
    
}

bool Graph::FindVertex(string vert1) {
    // search vert1 inside list<string> vertices
    list<string>::iterator iter;
    for(iter = vertices.begin(); iter != vertices.end(); iter++){
        if(*iter == vert1){
            return true;
        }
    }
    return false;
}

int Graph::FindEdgeCost(string vert1, string vert2) {
    pair<string,string> p(vert1, vert2);    
    // map<pair<string, string> ,int>::iterator iter;
    if(edges.find(p) != edges.end()){        
        return edges[p];    
    }    
    return -1;
}

int Graph::IsReachable(string vert1, string vert2) { //Pseudocode page 595
    list<string>::iterator iter;
    map<string, string> color;
    map<string, int> d;
    map<string, string> pi;
    queue<string> Q;
    string u;
    string v;
    // string adj;

    for(iter = vertices.begin(); iter != vertices.end(); iter++){
        color[*iter] = "WHITE";
        d[*iter] = INT_MAX;
        pi[*iter] = "";
    }
    color[vert1] = "GRAY";
    d[vert1] = 0;
    pi[vert1]= "NIL";
    Q.push(vert1);
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        map<pair<string, string> ,int>::iterator adj;
        for(adj = edges.begin(); adj != edges.end(); adj++){
            if(((*adj).first).first == u){
                v = ((*adj).first).second;
                if(color[v] == "WHITE"){
                    color[v] = "GRAY";
                    d[v] = d[u] + 1;
                    pi[v] = u;
                    Q.push(v);
                }

            }
        }
        color[u] = "BLACK";
    }
    int max = INT_MAX;
    if((d[vert2] < max) && (d[vert2] >= 0)){
        return d[vert2];
    }
    else{
        return -1;
    }
}

int main() {
    Graph G;
    string inp;
    std::cin >> inp;
    int weight;
    int edgeCost;
    
    while(inp != "END"){
        G.vertices.push_back(inp);
        std::cin >> inp;
    }
    string st;
    std::cin >> st;
    string end;

    while(st != "END"){
        std::cin >> end;
        std::cin >> weight;
        G.AddEdge(st, end, weight);
        std::cin >> st;
    }
    G.PrintOut();
    int OperationCode;
    while(OperationCode != 0){
        std::cin >> OperationCode;
        if(OperationCode == 1){
            string A;
            std::cin >> A;
            if(G.FindVertex(A)){
                std::cout << 1 << endl;
            }
            else{
                std::cout << 0 << endl;
            }
        }
        else if (OperationCode == 2){  
            string A;            
            std::cin >> A;
            string B;          
            std::cin >> B;
            edgeCost = G.FindEdgeCost(A, B);
            std::cout << edgeCost;
            std::cout << endl;
        }
         else if(OperationCode == 3){
            string A;            
            std::cin >> A;
            string B;
            std::cin >> B;
            edgeCost = G.IsReachable(A, B);
            std::cout << edgeCost;
            std::cout << endl;
        }
    }
}
