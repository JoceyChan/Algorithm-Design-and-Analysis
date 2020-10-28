#include <iostream>
#include <list>
#include <vector>

using namespace std;
//collisions when two or more items collide with each other
// iterators used to point at the memory addresses of  containers

void print_hash_table(list<int>* hash_table, int m){  
    // TODO: print hash table, follow the format
    list<int> listHash; // created a list
    list<int>::iterator iter;
    for(int i = 0; i < m; i++){
        listHash = hash_table[i];
        if(listHash.empty()){
            std::cout << i << " : " << endl;
        }
        else{
            std::cout << i << " : "; // prints index
            for(iter = listHash.begin(); iter != listHash.end(); iter++){
                std::cout << *iter << "->";
            }
        std::cout << " " << endl;
        }
    }
}

int hash_function(int key, int m){  
    return key % m;
}

void insert_key(list<int>* hash_table, int key, int m){  
    int idx = hash_function(key, m);  
    hash_table[idx].push_front(key);
}
void delete_key(list<int>* hash_table, int key, int m){  
    int idx = hash_function(key, m);  
    // delete from list: hash_table[idx] 
    list<int>::iterator iter; 
    for(iter = hash_table[idx].begin(); iter != hash_table[idx].end(); iter++){
         if(*iter == key){
            hash_table[idx].erase(iter);
            std::cout << key << " : DELETED" << endl;
            return;
        }
    }
    std::cout << key << " : DELETED FAILED" << endl;
}
void search_key(list<int>* hash_table, int key, int m){  
    int idx = hash_function(key, m);  
    // search inside list: hash_table[idx]
    list<int>::iterator iter; 
    list<int> listH = hash_table[key % m]; 
    // if(listH.empty()){
    //     std::cout << key << " : NOT FOUND" << endl;
    // } 
    // else{
        for(iter = listH.begin(); iter != listH.end(); iter++){
            if(*iter == key){
                std::cout << key << " : FOUND AT " << *iter <<"," << " " << endl; 
                return;
            }
        }
         std::cout << key << " : NOT FOUND" << endl;
    // }
  
}
int main(){  
    int m;  
    std::cin >> m;  
    list<int>* hash_table = new list<int>[m];  
    while(true){    
        char c;    
        std::cin >> c;    
        if(c == 'e'){      
            break;    
        } else if(c == 'o'){ // output hash table      
            print_hash_table(hash_table, m);    
        } else if(c == 'i'){  // insert key      
            int key;       
            std::cin >> key;       
            insert_key(hash_table, key, m);    
        } else if(c == 'd'){ // delete key    
            // finish   
            int key;       
            std::cin >> key;
            delete_key(hash_table, key, m);
        } else if(c == 's'){ // search key
            // finish  
            int key;       
            std::cin >> key;
            search_key(hash_table, key, m);   
        }  
    }  
    return 0;
}