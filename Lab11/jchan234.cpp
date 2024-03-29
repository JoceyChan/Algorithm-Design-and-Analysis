#include <sstream>
#include <iostream>
// #include <string>
//resources used Textbook, lab session

using namespace std;

struct Node {  
    int key;  
    Node* right;  
    Node* left;  
    Node* parent;

    Node(int key){
        this->key = key;
        this->parent = NULL;
        this->right = NULL;
        this->left = NULL;
    }
};
class BST{  
public: 
    Node *root;    
    BST(){
        this->root = NULL;
    }   
    void insert(Node* z) { //pseudocode page 294      
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
    void transplant(Node *u, Node *v) { //pseudocode page 296
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
    Node* treeMinimum(Node *n) { //pseudocode page 291
        while(n->left != NULL){
            n = n->left;
        }
        return n;
    }
    Node* search(Node* k){ //pseduo code page 291
        Node* x = root;
        while(x != NULL && k->key != x->key){
            if(k->key < x->key){
                x = x->left;
            }
            else{
                x = x->right;
            }
        }
        return x;
    }
    void deleteNode(Node* z) { //pseudocode page 298
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
            std::cout << n->key;
            std::cout << endl;        
            this->preorder(n->left);        
            this->preorder(n->right);      
        }    
    }    
    void inOrderTreeWalk(Node *n) {  //pseudocode page 288
        if(n != NULL){
            this->inOrderTreeWalk(n->left);
            std::cout << n->key;
            std::cout << endl;
            this->inOrderTreeWalk(n->right);
        }
    }  
    void postorder(Node *n){ 
        if(n != NULL){
            this->postorder(n->left);
            this->postorder(n->right);
            std::cout << n->key;
            std::cout << endl;
        }
    }
};
int main() {  
    // char inp[100];  
    BST* tree = new BST(); 
    int inp;
    string s; 
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
            tree->inOrderTreeWalk(tree->root);      
            std::cout << "++++++++++++++++++++"; 
            std::cout << endl;   
        } else if(s == "post"){    
            tree->postorder(tree->root);      
            std::cout << "++++++++++++++++++++";  
            std::cout << endl;  
        } else if(s == "i"){ 
            std::cin >> inp; 
            Node* key;
            key = new Node(inp);    
            tree->insert(key);    
        } else if(s == "d"){ 
            std::cin >> inp;     
            Node* key;
            key = new Node(inp);
            tree->deleteNode(key);   
        }    
        // cin.getline(inp, 100);  
    }
    return 0;
    //this used to access another function within the class
};
