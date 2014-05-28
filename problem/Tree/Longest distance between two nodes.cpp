/*

Longest distance between any two nodes in binary tree

*/

/*

solution: the longest distance should be in left subtree or in right subtree or it should pass through root. 
We can do it recursively.
O(nlogn) time, O(1) space

*/


struct Node {

  int val
  Node *plft;
  TreeNode *prgt;
  
  Node(int v) : val(v), plft(NULL), prgt(NULL) {}

};

int Height(Node* root) {

       if (root == NULL) {
             return 0;
       }

       int leftheight = Height(root->plft);
       int rightheight = Height(root->prgt);

       if (leftheight > rightheight) {

           return leftheight + 1;

       } else {

           return rightheight + 1;
       }
}

int LongestDistanceTwoNodes(Node *root) {

       if (root == NULL) {

          return 0;
       }

       int lheight = Height(root->plft);
       int rheight = Height(root->prgt);

       int llength = LongestDistanceTwoNodes(root->plft);
       int rlength = LongestDistanceTwoNodes(root->prgt);

       return max(lheight + rheight+ 1, max(llength, rlength));
}
