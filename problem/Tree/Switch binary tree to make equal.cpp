/*
Judge whether a binary tree can be equal to another by switching the left and right child (along with the subtree). 
Calculate how many switches is needed.
E.g
        a                        a
     b     c        ==       c       b           ==> switch 2 times
   d   e  f  g             g   f   d    e

*/
/*
solution: dfs recursion, use one parameter to record the final time
O(n) time

*/

#include<iostream>
#include<cassert>
using namespace std;

struct NODE {
    int val;
    NODE* Lft;
    NODE* Rgt;
 
    NODE(int n) : val(n), Lft(NULL), Rgt(NULL) {}
};
 
bool BinTreeSwitchEqualInner(NODE* node1, NODE* node2, int& switch) {
    switch = 0;
	
    if (node1 == NULL || node2 == NULL) return node1 == NULL && node2 == NULL;
 
    if (node1->val != node2->val) return false;
 
    int leftswitch, rightswitch;
    
    if (BinTreeSwitchEqualInner(node1->Lft, node2->Lft, leftswitch) && 
        BinTreeSwitchEqualInner(node1->Rgt, node2->Rgt, rightswitch)) {
        
        switch = leftswitch + rightswitch;
        return true;
    }
 
    if (BinTreeSwitchEqualInner(node1->Lft, node2->Rgt, leftswitch) && 
        BinTreeSwitchEqualInner(node1->Rgt, node2->Lft, rightswitch)) {
        
        switch = leftswitch +rightswitch + 1;  //add 1 to count switch left and right part
        return true;
    }
 
    return false;
}
 
int BinTreeSwitchEqual(NODE* root1, NODE* root2) {
    assert(root2 && root1);
 
    int switch = 0;
    bool result = BinTreeSwitchEqualInner(root1, root2, switch);
 
    return result ? switch : -1;
}

int main() {
    NODE *root1 = new NODE(5);
    root1->Lft = new NODE(1);
    root1->Rgt = new NODE(2);
    root1->Lft->Lft = new NODE(0);
    root1->Lft->Rgt = new NODE(7);
    root1->Rgt->Lft = new NODE(3);
    root1->Rgt->Rgt = new NODE(4);

    NODE *root2 = new NODE(5);
    root2->Lft = new NODE(2);
    root2->Rgt = new NODE(1);
    root2->Lft->Lft = new NODE(4);
    root2->Lft->Rgt = new NODE(3);
    root2->Rgt->Lft = new NODE(7);
    root2->Rgt->Rgt = new NODE(0);

    cout<<BinTreeSwitchEqual(root1, root2)<<endl;

    return 0;
}

