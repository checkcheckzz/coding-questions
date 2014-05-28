/*
A large family has a lot of members. Given a relation graph, check whether
two persons are relatives.
Note: if x and y are relatives, y and z are relatives, then x and z are relatives.
If x and y are relatives, the relatives of x are relatives to y and the relatives of 
y are relatives to x. 

/*

solution: use union-find set. 
O(nlogn+qlogn) time, O(1) space, n is the number of total relatives, q is the number of query
*/

#include<iostream>
#include <utility>
using namespace std;


int n,m,p;
//a large number for simplicity
int fa[5010];

int Find(int a) {
    //this optimization makes the tree as flat as possible
    if(fa[a] != a) fa[a] = Find(fa[a]);
    return fa[a];
}

void Merge(int a,int b) {

    fa[Find(a)] = Find(b);
}

void QueryRelatives(int n, pair<int, int> relatives[], int r,  pair<int, int> query[], int q) {
   
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    
    for (int i = 0; i < r; i++) {
		
        Merge(relatives[i].first, relatives[i].second);
    }
    for (int i = 0; i < q; i++) {
       
        if (Find(query[i].first) == Find(query[i].second)) {
            cout<<"They are relatives"<<endl;
        } else {
            cout<<"They are not relatives"<<endl;

        }     

    }
}

int main() {

    pair<int, int> pair1 = make_pair(2,3);
    pair<int, int> pair2 = make_pair(5,6);
    pair<int, int> pair3 = make_pair(1,2);
    pair<int, int> pair4 = make_pair(1,5);
    pair<int, int> pair5 = make_pair(3,4);
    pair<int, int> pair6 = make_pair(5,2);
    pair<int, int> pair7 = make_pair(1,3);
    pair<int, int> relatives[] = {pair3, pair4, pair5, pair6, pair7};
    pair<int, int> query[] = {pair1, pair2};
    QueryRelatives(6,relatives, 5, query, 2);
    return 0;
}

