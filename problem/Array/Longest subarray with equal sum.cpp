/*

Given 2 binary arrays A and B i.e. containing only 0s and 1s each of size N. Find indices i,j 
such that Sum of elements from i to j in both arrays is equal and j-i (i.e. the length
of the set i,j) is the maximum possible value.


*/

/*
solution:
Suppose we have two Arrays: 
A=[ 0 1 0 0 0 1 0 0 1 0 0] 
B=[ 1 0 1 1 1 0 1 1 0 1 0] 
Then we create two arrays : C[i] = A[i] - B[i] . D[i] = D[i-1] + C[i];
C=[-1 1 -1 -1 -1 1 -1 -1 1 -1 0] 
D=[-1,0,-1,-2,-3,-2,-3,-4,-3,-4,-4]

now we consider D-array. if D[i] == D[j] , it means sum( C[i,j ] ) ==0 . 
and since C[i] =A[i] - B[i] , now it means sum( A[i,j] ) == sum ( B[i, j] )
so now the task becomes find two indices i, j in D[], such that D[i]=D[j] and (j - i) is maximum.

we can use a map to solve this new problem

O(n) time, O(n) space

*/

#include<map>
#include<vector>
#include<cassert>
#include<iostream>
using namespace std;

int LongSubarrayEq(const vector<int>& a,const vector<int>& b) {
	int na = a.size(), nb = b.size();
	assert(na == nb);
	vector<int> c(na,0);
	
	for (int i = 0; i < na; ++i) {
	
		c[i] = a[i] - b[i];
	}
	
	for (int i = 1; i < na; ++i) {
	
		c[i] = c[i-1] + c[i];
    }
        
	int result = -1;

	map<int,int> exist;   //(c[i], i)
	map<int,int>::iterator it;
	exist.insert(pair<int,int>(0,-1));
	
	for (int i = 0; i < na; ++i) {
	
		it = exist.find(c[i]);	
		
		if ( it == exist.end()) {  // not exist
		
			exist.insert(it, pair<int,int>(c[i],i));
			
		} else {
		
			result = max(result, (i - it->second) );
		}
	}
	
	return result;
}


int main() {
	int n = 11;
	vector<int> a(n,0);  
    vector<int> b(n,0);  
	a[1] = 1, a[5] = 1, a[8] = 1;
	b[0] = 1, b[2] = 1, b[3] = 1, b[4] = 1,b[6] = 1, b[7] = 1, b[9] = 1;
	cout<<LongSubarrayEq(a,b)<<endl;
	
	/*
	int a[]={0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0};
	int b[]={1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0};
	*/

	return 0;
}
