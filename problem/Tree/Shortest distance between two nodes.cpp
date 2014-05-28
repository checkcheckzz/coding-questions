/*

Given two nodes of a Binary Tree, calculate the shortest distance between the two nodes.

*/

/*

solutions: 

Find the lowest common ancestor of the given nodes.
Find the distance between the lowest common ancestor and each given node separately.
Add the distances obtained above.

O(n) time, O(n) space

*/



#include<iostream>
#include<list>
using namespace std;

struct Node {
    int val;
    Node *plft;
    Node *prgt;
    Node(int v) : val(v), plft(NULL), prgt(NULL) {}

};

bool GetNodePath(Node *root, Node *node, list<Node*>& path) {
    if (root == node) return true;
 
    path.push_back(root);
    bool found = false;
    if (root->plft != NULL)
        found = getNodePath(root->plft, node, path);
    if (!found && root->prgt)
        found = getNodePath(root->prgt, node, path);
 
    if (!found)
        path.pop_back();
 
    return found;
}


Node* LastCommonNode(const list<Node*>& path1, const list<Node*>& path2) {

    list<Node*>::const_iterator iterator1 = path1.begin();
    list<Node*>::const_iterator iterator2 = path2.begin();
   
    Node *last = NULL;
 
    while (iterator1 != path1.end() && iterator2 != path2.end()) {
        if (*iterator1 == *iterator2)
            last = *iterator1;
 
        iterator1++;
        iterator2++;
    }
 
    return last;
}

Node *LastCommonAncestor(Node* root, Node* node1, Node* node2) {

    if(root == NULL || node1 == NULL || node2 == NULL) return NULL;

    list<Node*> path1;
    GetNodePath(root, node1, path1);
 
    list<Node*> path2;
    GetNodePath(root, node2, path2);
    return LastCommonNode(path1, path2);
}

int Height(Node *lca, Node *node,bool &found) {
    int lheight = 0, rheight = 0;
    if (lca) {

        if (found == false && lca == node) {  //lca is node1

            found = true;
            return 0;   //distance is 0

        } else if (found == false) {

            lheight = Height(lca->plft, node, found);
            rheight = 0;

            if(found == false) { //node is not in lca's left subtree

                rheight = Height(lca->prgt, node, found);
            }

            if(found == true) { //node is in lca's left or right subtree

                return lheight > rheight? 1+lheight : 1+rheight;

            } else {  //node is not in lca's subtree 

                return 0;
            }

        } else {

            return 0;
        }

    } else { //  if(lca)

        return 0;
    }
}

int ShortestDistance(Node *node1, Node* node2, Node *lca) {

    if (lca) {
        bool found = false;
        int dist1 = Height(lca, node1, found);
        cout<<"Distance of "<<node1->val<<": "<<dist1<<endl;

        found = false;
        int dist2 = Height(lca,node2,found);
        cout<<"Distance of "<<node2->val<<": "<<dist2<<endl;
        return dist1 + dist2;
    } else {
        return 0;
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
    root->prgt->prgt->plft = new Node(8);
    root->prgt->prgt->prgt = new Node(9);

    Node *node1 = root->prgt->prgt->plft;
    Node *node2 = root->prgt->plft;
    Node *lca = LastCommonAncestor(root, node1, node2);

    if (lca) {
        cout<<"Least Common Ancestor: "<<lca->val<<endl;
    }
    cout<<"Total distance: "<<ShortestDistance(node1, node2, lca)<<endl;
    return 0;

}
