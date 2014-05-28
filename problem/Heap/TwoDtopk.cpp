/*

Given n points on a two-dimensional plane, find the closest (euclidean distance) k points
to the point (0, 0).

*/


/*
solution1: use a maxheap. Build a maxheap with first k points, compare the rest
n-k points with the heap top, if larger than heap top, ignore, otherwise, add to heap.
If there are a lot of points stored on disk, we only need to scan the disk once.
O(nlogk) time, O(k) space

*/

/*
solution2: quickselect: O(n) average time, O(n^2) worst time
median of medians: O(n) worst time
If there are a lot of points stored on disk, we have to visit the disks many times.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node {
    double _x, _y;
    node(double x, double y): _x(x), _y(y){}
    node(): _x(0.0), _y(0.0){}
};

double Distance(node x, node target) {
	return pow(x._x - target._x, 2) + pow(x._y - target._y,2);
}

node target(0,0);

struct GreaterNote {

    bool operator() (const node a, const node b) {
        return Distance(a, target) < Distance(b, target);
    }
};



vector<node> GetKClosestNode(vector<node> nodes, int k) {
    priority_queue<node, vector<node>, GreaterNote > q; //build the max heap
    size_t size = nodes.size();
    if (size <= k) return nodes;
    for (size_t i = 0; i < k; i++ ){
        q.push(nodes[i]);
    }
    size_t num = k;
	
    while (num < size) {
        node top = q.top();
        if (Distance(nodes[num], target) < Distance(top, target)) {
            q.pop();
            q.push(nodes[num]);
			
        }

    }
    vector<node> res;
    while (!q.empty()){
        res.push_back(q.top());
        q.pop();
    }
    return res;
}


int main() {

    vector<node> nodes;
    node p1(0.2, 0.3);
    node p2(0.1, 0.5);
    node p3(0.4, 0.1);
    node p4(0.5, 0.2);
    node p5(0.0, 0.3);
    nodes.push_back(p1);
    nodes.push_back(p2);
    nodes.push_back(p3);
    nodes.push_back(p4);
    nodes.push_back(p5);
    int k = 3;
    vector<node> res = GetKClosestNode(nodes,3);
    for (size_t i = 0; i < res.size(); i++) {
    cout<<"("<<res[i]._x<<","<<res[i]._y<<")";
    }

    return 0;

}
