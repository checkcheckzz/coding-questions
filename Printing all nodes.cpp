/*

Print all Nodes at a given distance from a starting Node in a binary tree

*/



#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;




//The binary tree has parent link.

/*

solution:  print nodes in the subtree of the start node is easy. For those nodes as the start node's ancestor,  
use parent link to move up to print nodes, for those nodes as the start node's neighbor and those nodes in another
subtree of the full tree, call the print down function with proper node and update distance.

O(n) time, O(1) space

*/

struct TNode
{
    int val;
    TNode* plft;
    TNode* prgt;
	TNode* parent;

	TNode(int v) : val(v), plft(NULL), prgt(NULL), parent(NULL)  {}
};

//print node below given node 
void printDown(TNode * node, int k) {

	if(node == NULL || k < 0) return;

	if(k == 0) {
		cout<<node->val<<endl;
	} else {
		printDown(node->plft, k -1);
		printDown(node->prgt, k -1);	
	}
}
//print above node from given node 
void printAbove(TNode* node, int k) 
{
	if(node == NULL || k < 0) return;

	TNode *parent = NULL;
   
	parent = node->parent;

	

	while(parent != NULL)
	{
	    k--;
		if(k == 0)
			cout<<parent->val<<endl;
		else if(node == parent->plft)
		{
			printDown(parent->prgt, k-1);
		}
		else {
			printDown(parent->plft,k-1);
		}
		
		node = parent;
        parent  = parent->parent;
		

		
	}


}


void printDistancekNodeP(TNode *start, int k){

	if (start == NULL || k < 0) return;

	if (start->parent != NULL) {
	  printAbove(start, k);
	}

	printDown(start, k);

}


//The binary tree does not have parent link.

/*

solution:

*/



struct Node
{
    int val;
    Node* plft;
    Node* prgt;

	Node(int v) : val(v), plft(NULL), prgt(NULL) {}
};


//need finish this version

int main() {

	/*
	Node *root = new Node(1);
	root->plft = new Node(2);
	root->prgt = new Node(3);
	root->plft->plft = new Node(4);
	root->plft->prgt = new Node(5);
	root->prgt->plft = new Node(6);
	root->prgt->prgt = new Node(7);
	Node *start = root->prgt->prgt;
	*/
	

	TNode *root1 = new TNode(1);
	root1->plft = new TNode(2);
	root1->prgt = new TNode(3);
	root1->plft->parent = root1;
	root1->prgt->parent = root1;
	
	root1->plft->plft = new TNode(4);
	root1->plft->plft->parent = root1->plft;
	root1->plft->prgt = new TNode(5);
	root1->plft->prgt->parent = root1->plft;
	root1->prgt->plft = new TNode(6);
	root1->prgt->prgt = new TNode(7);
	root1->prgt->plft->parent = root1->prgt;
	root1->prgt->prgt->parent = root1->prgt;

	TNode *start1 = root1->prgt->prgt;
	TNode *start2 = root1->prgt;

	printDistancekNodeP(root1, 1);
	cout<<endl;
	printDistancekNodeP(root1, 2);
	cout<<endl;
	printDistancekNodeP(start1, 1);
	cout<<endl;
	printDistancekNodeP(start1, 2);
	cout<<endl;
	printDistancekNodeP(start1, 3);
	cout<<endl;
	printDistancekNodeP(start2, 1);
	cout<<endl;
	printDistancekNodeP(start2, 2);
	cout<<endl;
	printDistancekNodeP(start2, 3);
	cout<<endl;
	

	return 0;

}
