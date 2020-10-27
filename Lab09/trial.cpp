#include <iostream>
#include <list>
#include <vector>

using namespace std;

void print_hash_table(list<int>* hash_table, int m){  
    // TODO: print hash table, follow the format
  
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
   
}
void search_key(list<int>* hash_table, int key, int m){  
    int idx = hash_function(key, m);  
    // search inside list: hash_table[idx]


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
        } else if(c == 'o'){       
            print_hash_table(hash_table, m);    
        } else if(c == 'i'){       
            int key;       
            std::cin >> key;       
            insert_key(hash_table, key, m);    
        } else if(c == 'd'){       
            // finish   
            
        } else if(c == 's'){
            // finish  
            
        }  
    }  
    return 0;
}