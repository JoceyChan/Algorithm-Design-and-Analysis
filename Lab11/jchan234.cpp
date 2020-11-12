#include <sstream>
#include <iostream>
// #include <string>

using namespace std;

struct Node {  
    int key;  
    Node* right;  
    Node* left;  
    Node* parent;

    Node(int key){
        this->key = key;
        this->right = NULL;
        this->left = NULL;
        this->parent = NULL;
    }
};
class BST{  
public: 
    Node *root;    
    BST(){
        this->root = NULL;
    }   
    void insert(Node* z){      
        Node* y = NULL;      
        Node* x = this->root;      
        while(x != NULL){        
            y = x;        
            if(z->key < x->key){          
                x = x->left;        
            } 
            else{          
                x = x->right;        
            }      
        }      
        z->parent = y;      
        if(y == NULL){        
            root = z;      
        } 
        else if(z->key < y->key){        
            y->left = z;      
        } 
        else{        
            y->right = z;      
        }
    } 
    void transplant(Node *u, Node *v) { 
        if(u->parent == NULL){
            this->root = v;
        } 
        else if(u == u->parent->left){
            u->parent->left = v;
        }
        else{
            u->parent->right = v;
        }
        if(v != NULL){
            v->parent = u->parent;
        }
    }   
    Node* treeMinimum(Node *n){
        while(n->left != NULL){
            n = n->left;
        }
        return n;
    }
    Node* search(Node* j){
        Node* n = root;
        while(n != NULL && j->key != n->key){
            if(j->key < n->key){
                n = n->left;
            }
            else{
                n = n->right;
            }
        }
        return n;
    }
    void deleteNode(Node* z) {
        z = search(z);
        if(z == NULL){
            return;
        }
        else{
            if(z->left == NULL){
                transplant(z, z->right);
            }
            else if(z->right == NULL){
                transplant(z, z->left);
            }
            else{
                Node* y;
                y = treeMinimum(z->right);
                if(y->parent != z){
                    transplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y; 
                }
                else{
                    transplant(z, y);
                    y->left = z->left;
                    y->left->parent = y;
                }
            }
        }
    }
    void preorder(Node *n){      
        if(n != NULL){        
            cout<<n->key<<endl;        
            this->preorder(n->left);        
            this->preorder(n->right);      
        }    
    }    
    void inorder(Node *n){    
        if(n != NULL){
            this->inorder(n->left);
            cout << n->key <<endl;
            this->inorder(n->right);
        }
    }  
    void postorder(Node *n){ 
        if(n != NULL){
            this->postorder(n->left);
            this->postorder(n->right);
            cout << n->key << endl;
        }
    }
};
int main() {  
    // char inp[100];  
    BST* tree = new BST(); 
    string s; 
    int inp;
    // cin.getline(inp, 100);  
    while(true){
        cin >> s;    
        // string s(inp);
        if(s == "e"){      
            break;
        } else if(s == "pre"){      
            tree->preorder(tree->root);      
            std::cout << "++++++++++++++++++++"; 
            std::cout << endl;   
        } else if(s == "in"){    
            tree->inorder(tree->root);      
            std::cout << "++++++++++++++++++++"; 
            std::cout << endl;   
        } else if(s == "post"){    
            tree->postorder(tree->root);      
            std::cout << "++++++++++++++++++++";  
            std::cout << endl;  
        } else if(s == "i"){ 
            cin >> inp; 
            Node* key;
            key = new Node(inp);    
            tree->insert(key);    
        } else if(s == "d"){ 
            cin >> inp;     
            Node* key;
            key = new Node(inp);
            tree->deleteNode(key);   
        }    
        // cin.getline(inp, 100);  
    }
    return 0;
};