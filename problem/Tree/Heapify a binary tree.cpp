/*
Given a binary tree with integers, heapify the binary tree.
*/


/*
solution: recursive call to the leaf, and shiftup.
O(n) time
*/

#include<iostream>
using namespace std;

struct NODE  {
    int val;
    NODE* plft;
    NODE* prgt;
 
    NODE(int n) : val(n), plft(NULL), prgt(NULL) {}
};

void shiftUp(NODE *node) {

     if(!node) return; 
     
     NODE *largest = node;

	  //find the largest node
     if (node->plft != NULL && largest->val < node->plft->val) { 

        largest = node->plft; 

     }
     if (node->prgt != NULL && largest->val < node->prgt->val) {

        largest = node->prgt;

     }

	 // if root has the largest value, return
     if (largest == node) return;
    
	 //if not, swap the node's value with largest value
     int tmp = node->val;
     node->val = largest->val;
     largest->val = tmp;    

     shiftUp(largest);
}

void heapifyBinaryTree(NODE *root) {

    if (!root) return;

    if (root->plft) {
        heapifyBinaryTree(root->plft); 
    }    

    if (root->prgt) {

        heapifyBinaryTree(root->prgt);
     
    }

    shiftUp(root);

}



int main() {

    NODE *root = new NODE(1);
    root->plft = new NODE(2);
    root->prgt = new NODE(3);
    root->prgt->plft = new NODE(5);
    heapifyBinaryTree(root);
    cout<<root->val<<endl;
    cout<<root->plft->val<<endl;
    cout<<root->prgt->val<<endl;
    cout<<root->prgt->plft->val<<endl;
    return 0;

}

