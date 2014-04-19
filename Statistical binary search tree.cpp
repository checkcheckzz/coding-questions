/*

Statistical binary search tree

*/

#include<iostream>
using namespace std;

struct NODE {
    int val;
    NODE* pLft;
    NODE* pRgt;
    int size; //the size of the subtree rooted at that node
    NODE* pParent;
     
    NODE(int n, int sz = 1) : val(n), size(sz), pLft(NULL), pRgt(NULL), pParent(NULL) {}
 
    void setLeft(NODE* node) {
        if (node==NULL) return;
        pLft = node;
        node->pParent = this;
    }
 
    void setRight(NODE* node) {
        if (node==NULL) return;
        pRgt = node;
        node->pParent = this;
    }
};
 
 //O(logn) insert
void insert(NODE* node, NODE* tmp) {
    if (node==NULL|| tmp==NULL) return;
 
    node->size++;
 
    if (tmp->val >= node->val) {
    
        if (node->pRgt == NULL) {
        
            node->setRight(tmp);
            
        } else {
        
            insert(node->pRgt, tmp);
        } 
        
    } else {
    
        if (node->pLft == NULL) {
        
            node->setLeft(tmp);
            
        } else {
        
            insert(node->pLft, tmp);
        }   
    }
}

//find the n'th smallest element stored in the tree in O(logn) time

NODE* select(NODE* root, int n) {
    if (root==NULL || n <= 0) return NULL;
 
    NODE* cur = root;
    
    int cursum = 0;
    
    do {
    
        int lefttreesize = 1 + (cur->pLft == NULL ? 0 : cur->pLft->size);
        int totalsum = cursum + lefttreesize;
 
        if (totalsum == n) return curn;
 
        if (totalsum < n)  {  //  add the size of left subtree
        
            cursum += lefttreesize;
            
        }
        
        cur = (totalsum > n ? cur->pLft : cur->pRgt);  //continue to search left or right subtree
        
    } while (cur!=NULL);
 
    return NULL;
}

//find the rank of element node in the tree in O(logn) time

int getNum(NODE* root, NODE* node) {
    if (root == NULL|| node == NULL) return 0;
 
    if (node == root) return node->pLft == NULL ? 1 : 1 + node->pLft->size;
 
    NODE* cur = node;
    int result = 1;
    while (cur->pParent != NULL) {
    
        if (cur == cur->pParent->pRgt) { // if node is its parent right child
            result += 1 + (cur->pParent->pLft == NULL ? 0 : cur->pParent->pLft->size); 
        }
        
        cur = cur->pParent;
    }
 
    return result;
}

int main() {
    NODE *root = new NODE(3);
    insert(root, new NODE(1));
    insert(root, new NODE(5));
    NODE *p1 = new NODE(4);
    insert(root,p1);
    cout<<root->size<<endl;//4
	
    cout<<select(root,1)->val<<endl;
    cout<<select(root,2)->val<<endl;
    cout<<select(root,3)->val<<endl;
    cout<<select(root,4)->val<<endl;
    cout<<getNum(root, p1)<<endl;
    return 0; 

}

