/*

Kth maximal element of array c, where c[k] = a[i] + b[j], a, b are another two arrays

*/


#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

/*
solution1:
sort the two arrays(we assume they are sorted at the beginning), use a max heap，suppouse we pop (a[i]+b[j]) from heap,
then push a[i-1]+b[j] and  a[i]+b[j-1] into heap.
O(mlogm)+O(nlogn)+O(klogk) time, O(k) space
*/

struct node {
    int a,b,val; //element index and their value sum
    node(int _a,int _b,int v): a(_a),b(_b),val(v) {}
	
};

struct GreaterNote {

    bool operator() (const node a, const node b) {
        return a.val < b.val;
    }
};

int FindKthSum1(int A[],int m,int B[],int n,int k) {

	priority_queue<node, vector<node>, GreaterNote > q; //build the max heap
	q.push(node(0,0,A[0]+B[0]));
	set<pair<int,int> > visited;
	visited.insert(pair<int,int>(0,0));
	while(!q.empty()) {
	
		node t = q.top();
		q.pop();
		k--;
		if(k == 0) return t.val;
		
		set<pair<int,int> >::iterator it;
		if(t.a+1<m&&(it=visited.find(pair<int,int>(t.a+1,t.b)))==visited.end()) { 
		
			visited.insert(it,pair<int,int>(t.a+1,t.b));
			q.push(node(t.a+1,t.b,A[t.a+1]+B[t.b])); //push A[a+1]+B[b]
		}
		
		if(t.b+1<n&&(it=visited.find(pair<int,int>(t.a,t.b+1)))==visited.end()) {
		
			visited.insert(it,pair<int,int>(t.a,t.b+1));
			q.push(node(t.a,t.b+1,A[t.a]+B[t.b+1])); //push A[a]+B[b+1]
		}
	}
	
	return -1;
}

/*

solution2: we assume the two arrays are sorted (increasing), and we want to find the kth minimal sum.
Binary search from a[0]+b[0] to a[m-1]+b[n-1], If there are at least k sums whose value is less than the target value (mid of two end value), 
record this target value, continue search. 
O(mlogm)+O(nlogn) + O(log(maxsum-minsum))*O(m+n) time, O(1) space

*/

int CountSmaller(int A[],int m,int B[],int n,int piv) {

	int pa = 0,pb = n - 1;
	int cnt = 0;
	for(; pa < m; ++pa) {
	
		if(A[pa] > piv) break;
		
		while(pb >= 0 && A[pa] + B[pb] > piv) {
		
			pb--;
			
	 	}	
		cnt + = pb + 1;   //count the number of sum less than piv
	}
	
	return cnt;
}
int FindKthSum2(int A[],int m,int B[],int n,int k) {

	int l = A[0] + B[0];
	int r = A[m-1] + B[n-1];
	int ans = -1;
	while (l <= r) {
	
		int mid=l+((r-l)>>1);
		if (CountSmaller(A,m,B,n,mid) >= k ) {
		
			ans = mid;
			r = mid - 1;
		} else {
		
			l = mid + 1;
	}
	
	return ans;
}


int main() {
	
    int A[4] = {4,3,2,1};
    int B[2] = {3,2};
		
    int AA[4] = {1,2,3,4};
    int BB[2] = {2,3};
	 
    int res1 = FindKthSum1(A,4,B,2,3);
    int res2 = FindKthSum2(AA,4,BB,2,3);
    cout<<res1<<endl;
    cout<<res2<<endl;
    return 0;	
}

