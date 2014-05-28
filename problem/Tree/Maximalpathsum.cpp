/*

Given a N-way tree, find the maximum path sum. The path may start and end at any node in the tree.

*/

/*

solution: calculate each path sum for each child, add it to maximal path if it is positve   
O(n) time, O(1) space
*/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children; 
    TreeNode(int n) : val(n), children() {}
};

int MaxPathSumInner(TreeNode *node, int &maxSoFar) {
    if (node == NULL) return 0;
	int maxPath = node->val;
	int tempPath = INT_MIN;
	vector<TreeNode*>::iterator it = node->children.begin();
	for (; it != node->children.end(); it++) {
		int maxchild = MaxPathSumInner(*it, maxSoFar);
		
		if (maxchild > 0)  maxPath += maxchild;
		if (maxchild > tempPath) tempPath = maxchild;
	}
	if (maxPath > maxSoFar) maxSoFar = maxPath;
	int res = node->val;
	return max(res, res + tempPath); //note path definition
}


int MaxPathSum(TreeNode *root) {

    if (root == NULL) return 0;
    int maxSoFar = root->val;
    MaxPathSumInner(root, maxSoFar);
    return maxSoFar;
}

int main() {

    TreeNode *root = new TreeNode(-10);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *p3 = new TreeNode(4);
    root->children.push_back(p1);
    root->children.push_back(p2);
    root->children.push_back(p3);
    TreeNode *p4 = new TreeNode(5);
    TreeNode *p5 = new TreeNode(-1);
    p2->children.push_back(p4);
    p2->children.push_back(p5);
    TreeNode *p6 = new TreeNode(6);
    p5->children.push_back(p6);
    TreeNode *p7 = new TreeNode(-1);
    p6->children.push_back(p7);
    cout<<MaxPathSum(root);

    return 0;

}




