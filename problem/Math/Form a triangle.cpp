/*
Given an unsorted positive integer array, find three integers to form a triangle.
*/

/*
solution: sort the array at first. Scan the array once to check a1+a2>a3, return.
O(nlogn) time, O(1) space
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool FindTriangle(vector<int> arr) {

	if (arr.size() <3) return false;

	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < arr.size()-2; ++i) {

		if (arr[i] + arr[i+1] > arr[i+2]) {

			return true;
		}

	}

	return false;

}

int main() {

	int arr1[] = {1, 4, 6, 3, 8, 2};
	int arr2[] = {1, 2, 1, 3};
	vector<int> arr1v(arr1, arr1 + sizeof(arr1) / sizeof(int));
	vector<int> arr2v(arr2, arr2 + sizeof(arr2) / sizeof(int));
	cout<<FindTriangle(arr1v)<<endl;
	cout<<FindTriangle(arr2v)<<endl;
	return 0;
}