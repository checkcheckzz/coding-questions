/*

Given a binary tree, find the largest subtree which is a binary search tree. 
Here largest subtree means a subtree with largest number of nodes in it, including all of its descendants

*/

/*
solution: bottom up upper and lower bound
O(n) time
*/

#include<iostream>
#include<cassert>
#include<stack>
using namespace std;


struct NODE  {
    int val;
    NODE* pLft;
    NODE* pRgt;
 
    NODE(int n) : val(n), pLft(NULL), pRgt(NULL) {}
};

 
int GetLargestBSTInner(NODE* Node, int& minbound, int& maxbound, NODE*& maxbstroot, int& maxbstnum) {
    
    assert(Node);
 
    minbound = Node->val;
    maxbound = Node->val;
 
    int result = 1; //count root
    bool bivalid = false;
    if (Node->pLft != NULL) {
    
        int lftmax, lftmin;
        int numnodes = GetLargestBSTInner(Node->pLft, lftmin, lftmax, maxbstroot, maxbstnum);
        if (numnodes <= 0 || lftmax > pNode->val) { //check invalid
        
            bivalid = true; 
        
        }  else  {  //pNode->pLft is a valid BST
        
            result += numnodes;   //count size of left subtree
            minbound = lftmin;    //update bound
        }
    }
 
    if (Node->pRgt != NULL) {
    
        int rgtmax, rgtmin;
        int numnodes = GetLargestBSTInner(Node->pRgt, rgtmin, rgtmax, maxbstroot, maxbstnum);
        if (numnodes <= 0 || rgtmin < pNode->val) {  //check invalid
        
            bivalid = true;
            
        } else {   //pNode->pRgt is a valid BST
        
            result += numnodes; //count size of right subtree
            maxbound = rgtmax; //update bound
        }
    }
 
    if (bivalid) return -1; //return value identify a BST or not
 
    if (result > maxbstnum) {  //update maximal BST
    
        maxbstroot = Node;
        maxbstnum = result;
    }
 
    return result;
}
 
//Input root of a BT and return the root of largest BST 
NODE *GetLargestBST(NODE *root) {
    
    if (root == NULL) return NULL;
 
    NODE *result = NULL;
    int maxbstnum = 0;
    int minbound, maxbound;
    GetLargestBSTInner(root, minbound, maxbound, result, maxbstnum);
 
    return result;
}

void InOrderTravel(NODE* root) {
    assert(root);
 
    stack<NODE*> stk;
    NODE* cur = root;
    while (NULL != cur) {
    
        stk.push(cur);
        cur = cur->pLft;
    }
 
    while (!stk.empty()) {
    
        cur = stk.top();
        cout<<cur->val<<endl;
        stk.pop();
 
        cur = cur->pRgt;
        while (NULL != cur) {
        
            stk.push(cur);
            cur = cur->pLft;
        }
    }
}

int main() {
    NODE *root = new NODE(5);
    root->pLft = new NODE(3);
    root->pRgt = new NODE(6);
    root->pLft->pRgt = new NODE(4);
    root->pLft->pLft = new NODE(2);
    root->pRgt->pRgt = new NODE(8);
    InOrderTravel(GetLargestBST(root));
    return 0;
	
}

