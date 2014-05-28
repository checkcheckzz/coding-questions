/*

Iterative Preorder, Inorder, Postorder traversal of binary tree

*/


/*
solution: use stack
O(n) time, O(n) space

*/

#include<cstdlib>
#include <cassert>
#include<stack>
#include<iostream>
using namespace std;

struct NODE {
    int val;
    NODE* pLft;
    NODE* pRgt;
 
    NODE(int n) : val(n), pLft(NULL), pRgt(NULL) {}
};

//postorder
void PostOrderTravel(NODE* root) {
    assert(root);
 
    stack<NODE*> stk;
    NODE* cur = root;
    while (cur != NULL) {
    
        stk.push(cur);
        cur = cur->pLft;
    }
 
    NODE* prev = NULL;
    
    while (!stk.empty()) {
    
        NODE* tmp = stk.top();
		
 
        if (tmp->pRgt != NULL && prev != tmp->pRgt) {
        
            NODE* iter = tmp->pRgt;
            while (iter != NULL) {
            
                stk.push(iter);
                iter = iter->pLft;
            }
            
        } else {
        
            cout<<tmp->val<<endl;
            prev = tmp;
            stk.pop();
        }
    }
}
 
//preorder
void PrevOrderTravel(NODE* root) {
    assert(root);
 
    stack<NODE*> stk;
    stk.push(root);
 
    while (!stk.empty()) {
    
        NODE* top = stk.top();
        stk.pop();
 
        cout<<top->val<<endl;
 
        if (top->pRgt != NULL) stk.push(top->pRgt);
        
        if (top->pLft != NULL) stk.push(top->pLft);
    }
}
 
//inorder

void InOrderTravel(NODE* root) {
    assert(root);
 
    stack<NODE*> stk;
    NODE* cur = root;
    while (cur!=NULL) {
    
        stk.push(cur);
        cur = cur->pLft;
    }
 
    while (!stk.empty()) {
    
        cur = stk.top();
        cout<<cur->val<<endl;
        stk.pop();
 
        cur = cur->pRgt;
        
        while (cur!=NULL) {
        
            stk.push(cur);
            cur = cur->pLft;
        }
    }
}

int main(){

    NODE *head = new NODE(2);
    head->pLft = new NODE(1);
    head->pRgt = new NODE(3);
    PrevOrderTravel(head);
    InOrderTravel(head);
    PostOrderTravel(head);
    return 0;
}

