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

int height(Node* root) {

       if(root == NULL) {
             return 0;
       }

       int leftheight = height(root->plft);
       int rightheight = height(root->prgt);

       if(leftheight > rightheight) {

              return leftheight + 1;

       } else {

              return rightheight + 1;
       }
}

int longestDistanceTwoNodes(Node *root) {

       if(root == NULL) {

          return 0;
       }

       int lheight = height(root->plft);
       int rheight = height(root->prgt);

       int llength = diameter(root->plft);
       int rlength = diameter(root->prgt);

       return max(lheight + rheight+ 1, max(llength, rlength));
}
