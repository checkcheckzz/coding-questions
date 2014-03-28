/*
Find the right most node in each level of a binary tree
*/

/*
solution: preorder traversal but with right child at first
O(n) time
*/



#include<iostream>
#include<vector>
using namespace std;

struct NODE
{
    int val;
    NODE* pLft;
    NODE* pRgt;
 
    NODE(int n) : val(n), pLft(NULL), pRgt(NULL) {}
};

void getRightMostBTInner(NODE* Node, vector<NODE*> &vec, int Lev)
{
    if (Node == NULL) {
    
        return;
    }    
 
    if (Lev >= vec.size()) {
    
        vec.push_back(Node);
	cout<<Node->val;
    }
	
 
    getRightMostBTInnerNode->pRgt, vec, Lev+1);
    getRightMostBTInner(Node->pLft, vec, Lev+1);
}
 
vector<NODE*> getRightMostBT(NODE* root)
{
    vector<NODE*> vec;
    getRightMostBThelp(root, vec, 0);
 
    return vec;
}

int main(){

	NODE *head=new NODE(2);
	head->pLft=new NODE(3);
	head->pRgt=new NODE(5);
	head->pRgt->pRgt=new NODE(7);

	getRightMostBT(head);
	
	return 0;
}


