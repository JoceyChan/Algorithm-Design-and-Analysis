#include <iostream>
#include <vector>
#include <queue>
#include <string>

// Resources used Book, Lab session
// Outside help: Alberto V.

using namespace std;

struct Node { // code from lab 11 when building a Node
    public: 
    char data;  
    int frequency;
    Node* right;  
    Node* left;  

    Node(char data, int frequency){
        this->data = data;
        this->frequency = frequency;
        this->right = NULL;
        this->left = NULL;
    }
};

//arranges address, front point to node w/min freq
class comparison {
    public:
    bool operator()(Node *left, Node *right){
        return ((left->frequency) >= (right->frequency));
    }
};

void printHuffmanCode(Node *root, char c, string a){
    if(!root){ // if root is NULL then return
        return;
    }
    if(root->data == c){ 
        std::cout << a << endl;
    }
    //recursively travserse, left add "0"
    printHuffmanCode(root->left, c, a + "0");
    //recursively travserse, right add "1"
    printHuffmanCode(root->right, c, a + "1");
}

void Huffman(char data, int frequency[], int N){ //pseudocode page 431
    Node *left;
    Node *right;
    Node *top;
    //creating node
    priority_queue<Node*, vector<Node*>, comparison> C;
    data = 'A';
    for(int i = 0; i < N; i++){ 
        data += 1;
        C.push(new Node(data, frequency[i])); // pushing--filling up priority queue 
    }
    // while(C.size() > 1){
    for(int i = 1; i < N; i++){ //Extract the two minimum freq items from min heap
        left = C.top(); // node 1 get top node
        C.pop(); 
        right = C.top(); // node 2 get top node
        C.pop();
        Node* z = new Node('$', left->frequency + right->frequency); //allocating a new node z and merging
        z->left = left; //  extracting min
        z->right = right; // extracting min
        C.push(z); //inserting 
    }
    string a = "";
    char c = 'A';
    for(int i = 0; i <= N; i++){
        printHuffmanCode(C.top(), c, a);
        c += 1;
        a = "";
    }
}

int main(){
    int N;  
    std::cin >> N;  
    char data;
    int* frequency = new int[N];

    for(int i = 0; i < N; i++){
        std::cin >> frequency[i];
    }

    Huffman(data, frequency, N);
    
    return 0;
}