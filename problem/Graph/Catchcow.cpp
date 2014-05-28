/*

Given two integers n and k, there are three operations n-1, n+1 and n*2.
Calculate the minimal number of operations such that n == k.

*/

/*
solution: BFS. It is similar to a problem where we want to  find the shortest path from n to k.
O(k-n) time, O(k) space
*/

#include<iostream>
#include <queue>
using namespace std;



struct Point {
	int value, step;
};

int Operation(int n,int choice) {

	switch (choice) {

	    case 0:return n-1;
	    case 1:return n+1;
	    case 2:return n*2;
	}
}

int MinimalOperations(int start, int end, bool visit[]) {

	visit[start] = true;
	queue <Point> q;
	Point s,e;
	s.value = start;
	s.step = 0;
	q.push(s);
	while (!q.empty()) {

	    s = q.front();

	    q.pop();
		if (s.value == end) { //reach end
			break;
		}  
		for (int i=0;i<3;i++) {

			e.value = Operation(s.value, i);
			e.step = s.step + 1;

			if (e.value >= 0 && e.value <= 10000 && visit[e.value] == false) {

				q.push(e);
				visit[e.value]=true;
			}
		}
	}
	return s.step;
}


int main(){

	int n = 5, k = 80;
	bool visit[10000] = {0};
	cout<<MinimalOperations(n, k, visit)<<endl;
	return 0;

}