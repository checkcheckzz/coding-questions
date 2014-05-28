/*
Given a text file with 3 columns -- all integers:

id,parent,weight

each line is a node, 'parent' refers to 'id' of another node.

Print out, for each node, the total weight of a subtree below this node. There is no circle.
Here we assume each node has only one parent but may have multiple children.
It is not hard to change the code to handle node with multiple parents.

*/


/*

solution: visit the leaf nodes at first, decrease their parent's outdegree
and add their weight to their parent's weight.
O(n) time, O(n) space

*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void PrintSubTreeSum(vector<vector<int> > &relation, int node) {   
    int size = relation.size();
    if (node == 0 || size == 0) return;
    vector<int> outdegree(node, 0);
    vector<int> totalweight(node,0);
    vector<int> orgweight(node,0);
    vector<int> parentindex(node,-1);
	
    for (int i = 0;i < size;i++) {

        outdegree[relation[i][1]]++;
        totalweight[relation[i][0]] = relation[i][2];
        parentindex[relation[i][0]] = relation[i][1];
        orgweight[relation[i][0]] = relation[i][2];
    }

    queue<int> q;
	
    for (int i = 0;i < node;i++) {

        if (outdegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {

        int curindex = q.front();
        q.pop();

		int diffweight = totalweight[curindex] - orgweight[curindex];
		if (diffweight == 0) {
			cout << "Id " << curindex << " is a leaf node"<<endl;
		} else {

        cout << "Id " << curindex << " with subTree weight : " << diffweight<< endl;

		}

        int parindex = parentindex[curindex];

        if (parindex < 0) continue;
        outdegree[parindex]--;
        totalweight[parindex] += totalweight[curindex];
        if (outdegree[parindex] == 0) q.push(parindex);
    }
}


int main() {

    vector<vector<int> > relation;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;
    a.push_back(1);
    a.push_back(0);
    a.push_back(3);
    relation.push_back(a);
    b.push_back(2);
    b.push_back(0);
    b.push_back(4);
    relation.push_back(b);
    c.push_back(3);
    c.push_back(0);
    c.push_back(5);
    relation.push_back(c);
    d.push_back(4);
    d.push_back(1);
    d.push_back(3);
    relation.push_back(d);
    int node = 5;
    PrintSubTreeSum(relation, node);
	return 0;
}
