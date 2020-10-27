#include <iostream>
#include <list>
#include <vector>

using namespace std;

void print_hash_table(list<int>* hash_table, int m){  
    // TODO: print hash table, follow the format
    list<int> listHash;
    list<int>::iterator iter;
    for(int i = 0; i < m; i++){
        listHash = hash_table[i];
        if(listHash.empty()){
            std::cout << i << " : " << endl;
        }
        else{
            std::cout << i << " : ";
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
            break;
            std::cout << key << " : DELETED_FAILED" << endl;

        }
        if(iter != hash_table[idx].end()){
            hash_table[idx].erase(iter);
            std::cout << key << " : DELETED" << endl;

        }
        // std::cout << *iter << "->" << ";" << endl;
    }
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
            int key;       
            std::cin >> key;
            delete_key(hash_table, key, m);
        } else if(c == 's'){
            // finish  
            int key;       
            std::cin >> key;
            search_key(hash_table, key, m);   
        }  
    }  
    return 0;
}