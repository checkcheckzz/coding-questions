/*

Given an array and a number k, if there exists an element arr[i] such that its duplicates
lies in arr[i-k] and arr[i+k],return true, else return false

*/

/*
solution: use a set to store and check the duplicates
O(nlogk) time, O(k) space
*/

#include<iostream>
#include<cassert>
#include<set>
using namespace std;

bool HasDupk(int arr[], int len, int k) {

	assert(arr && k >= 0 && k < len && len > 0);
	set<int> checked;
	
	for (int i = 0; i < k; ++i) {
	
		int tmp = arr[i];
		
		if (checked.find(tmp) != checked.end()) {
		
			return true;
		}
		
		checked.insert(tmp);
	}

	for (int i=k; i<len; k++) {
	
		int tmp = a[i];
		if (checked.find(tmp) != checked.end()) {
		
			return true;
	        }		
		checked.erase(a[i-k]);
		checked.insert(tmp);
	}

	return false;
}

int main() {

    int arr[]={3, 1, 2, 1, 2, 3, 9, 1};
    int k = 2;
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<HasDupk(arr, len, k)<<endl;
    return 0;
}

