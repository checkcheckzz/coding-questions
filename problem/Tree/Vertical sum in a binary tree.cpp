/*

Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums of different vertical lines.

Examples:

      1
    /   \
  2      3
 / \    / \
4   5  6   7

Vertical-Line-1  vertical sum is 4
Vertical-Line-2: vertical sum is 2
Vertical-Line-3:  vertical sum is 1+5+6 = 12
Vertical-Line-4:  vertical sum is 3
Vertical-Line-5:  vertical sum is 7

*/

/*

solutuion:  calculate horizontal distances from root for all nodes. If two nodes have the same horizontal distance, then they are on same vertical line. 
HD for root is 0, a right edge (edge connecting to right subtree) is considered as +1 horizontal distance and a left edge is considered as -1 horizontal distance. 

Do an inorder traversal and calcuate the horizontal distance recursively.

O(n) time, O(n) space

*/

#include<iostream>
#include<unordered_map>
using namespace std;

struct Node {
   int val;
   Node *plft;
   Node *prgt;
  
   Node(int v) : val(v), plft(NULL), prgt(NULL) {}
};


void GetHorizontalDistance(Node *root, int hd, unordered_map<int, int> &hdmp) { 

        
    if (root == NULL) return;
  
        
    GetHorizontalDistance(root->plft, hd - 1, hdmp);
  
        
    int prevsum = (hdmp.find(hd) == hdmp.end()) ? 0 : hdmp.find(hd)->second;

    if (hdmp.find(hd) == hdmp.end()) {

        hdmp.insert(make_pair<int,int>(hd, prevsum + root->val));
  
    } else {

        hdmp[hd] = prevsum + root->val;
    }

        GetHorizontalDistance(root->prgt, hd + 1, hdmp);
    }

void VerticalSum(Node *root) {

    if (root == NULL) return;

    unordered_map<int, int> hdmp;
    GetHorizontalDistance(root, 0, hdmp);

    if (!hdmp.empty()) {

        for (unordered_map<int, int>::iterator it = hdmp.begin(); it != hdmp.end(); ++it ) {

            cout<< it->second <<" "<<endl;

        }

   }

}

int main() {

    Node *root = new Node(1);
    root->plft = new Node(2);
    root->prgt = new Node(3);
    root->plft->plft = new Node(4);
    root->plft->prgt = new Node(5);
    root->prgt->plft = new Node(6);
    root->prgt->prgt = new Node(7);

    VerticalSum(root);

    return 0;

}

