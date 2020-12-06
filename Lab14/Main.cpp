#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class node{
    public:
    char val;
    int freq;
    node* left;
    node*right;

    node(char v, int f){
        val=v;
        freq=f;
        left=NULL;
        right=NULL;
    }
};

///comparator class for the Priority queue of the pointer
///arranges the address such that the one at the front point to node with the minimum freq
class MyCompare {
    public:
    bool operator()(node *a, node *b) {
        return (a->freq) >= (b->freq);
    }
};
///generate huffamnCode takes the address of the root and a string code that stores
///the path traversed in the huffman tree as a string
void geneatetHuffmanCode(node * &root, string* huffman_code, string code){
///if root->val is NOT '$' then it means it is a laef node.
/// so its huffman-code needs to e stored in the huffman_code array
    if(root->val!='$'){
        huffman_code[root->val-'A']=code; /// stroing huffman_code at proper index in the array
        return;
    }
    /// recursively travserse the huffamn tree left . While moving left, add '0' to the code.
    if(root->left!=NULL) 
        geneatetHuffmanCode(root->left,huffman_code,code+"0");

    /// recursively travserse the huffamn tree right . While moving right, add '1' to the code.
    if(root->right!=NULL) 
        geneatetHuffmanCode(root->right,huffman_code,code+"1");

}

int main() {
   int n; 
   cin>>n;

   priority_queue<node*,vector<node*>, MyCompare> pq;
   for(int i=0;i<n;i++){
        cout<<char(i);
        int a; cin>>a;
   ///creating a node using new operator and pushing its value in the priority queue
        pq.push(new node('A'+i,a));
    }

   ///At preasent there is n node in the priority queue.

   ///if there is atleast 2 node in the pq, then get into loop
   while(pq.size()>1){

        node* n1=pq.top(); pq.pop(); ///get the top node and pop it
        node* n2=pq.top(); pq.pop(); ///get the top node and pop it

        ///get a new node with frequence equal to sum of frequency of the two popped node
        node *n3=new node('$',n1->freq+n2->freq);/// '$' means that the node is internal node


        n3->left=n1; ///make left point to the n1 node
        n3->right=n2; ///make right point to n2 node
        pq.push(n3); ///push n3 into pq
    }

   /// This way at each repetition of the While Loop, we take take 2 lesser frequent node
   /// using them form a new node whose val is '$' and whose frequency is sum of frequency of these two node
   /// The newly added node becomes the parent of the n1 and n2 nodes in the huffman tree.It
   /// strores the address of the n1 and n2 pointer.

   /// Repeating this process till there is only one node in the priority queue, which
   /// is the root node of the Huffman tree.

   node* rootPtr= pq.top(); ///rootPtr is the rootNode of the huffman Tree.

   string huffman_code[n]; ///huffman_code sores the huffman code of all the character
   for(int i=0;i<n;i++) huffman_code[i]=""; ///initializinf the huffman_code of all character with 0

///calling generateHuffmancide function
   geneatetHuffmanCode(rootPtr,huffman_code,"");
   ///printing huffman code of each character
   for(int i=0;i<n;i++) 
    cout<<char(+i)<< huffman_code[i]<<endl;

   cout<<endl;
  


}