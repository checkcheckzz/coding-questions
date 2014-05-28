/*

Second largest node in the binary search tree

*/

/*
  
solutions: iterate right subtree to find the lastest node. If the node does not have left child, the node's parent is the second largest node, 
otherwise, find the largest node in its left subtree.
O(n) time, O(1) space  
   
*/


struct Node {
  int val;
  Node *plft;
  Node *prgt;
  
  Node(int v) : val(v), plft(NULL), prgt(NULL) {}
};




Node *SecondLargestNode(NODE *root) {


      if (root == NULL || root->plft == NULL && root->prgt == NULL) return NULL;

      NODE *iter = root;
      NODE *parent = NULL;
 
      while (iter->prgt != NULL) {
   
        parent = iter;

        iter = iter->prgt;

      }

     if (iter->left == NULL) return parent;

     NODE *leftsub = iter->plft;

     while (leftsub=>prgt != NULL) {
   

         leftsub = leftsub=>prgt;

     }
     
     return leftsub;

}

