#include <sstream>
#include <iostream>
#include <string>

using namespace std;

struct Node {  
    int key;  
    Node* left;  
    Node* right;  
    Node* parent;
};
class BST{  
    public:    
        BST();    
        Node *root;    
        void insert(int key){      
            Node* y;      
            Node* x = this->root;      
            while(x != NULL){        
                y = x;        
                if(key < x->key){          
                    x = x->left;        
                } 
                else{          
                    x = x->right;        
                }      
            }      
            Node* z;      
            z->key = key;      
            z->parent = y;      
            if(y == NULL){        
                this->root = z;      
            } 
            else if(z->key < y->key){        
                y->left = z;      
            } 
            else{        
                y->right = z;      
            }    
        };      
        void deleteNode(int key) { 
             key = key;
        };
        void preorder(Node *n){      
            if(n != NULL){        
                cout<<n->key<<endl;        
                this->preorder(n->left);        
                this->preorder(n->right);      
            }    
        };    
        void inorder(Node *n){    

        };  
        void postorder(Node *n){    

        };
};
int main() {  
    char inp[100];  
    BST tree;  
    cin.getline(inp, 100);  
    while(true){    
        string s(inp);
        if(s[0] == 'e'){      
            break;
            while(true){    
                string s(inp);    
                if(s[0] == 'e'){      
                    break;    
                } else if(s.substr(0,3) == "pre"){      
                    tree.preorder(tree.root);      
                    cout<<"++++++++++++";    
                } else if(s.substr(0,2) == "in"){    

                } else if(s.substr(0,4) == "post"){    

                } else if(s[0] == 'i'){      
                    int key = stoi(s.substr(2,s.length()-2));      
                    tree.insert(key);    
                } else if(s[0] == 'd'){      
                    int key = stoi(s.substr(2,s.length()-2));    
                }    
                cin.getline(inp, 100);  
            }
            return 0;
        }
    }
};