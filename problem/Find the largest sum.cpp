/*
Find the largest sum of 3 integers in a row in an array
using least number of addition.

*/

/*
solution: consider 4 number in a row at once, i.e., a, b, c, d. Calculate b+c+max(a,d) such that two addition solve two 3-tuples.
For an array size of n, there are n-2 3-tuples. 
O(n-2) addition, O(1) space

*/

#include<iostream>
#include<cassert>
using namespace std;

int FindLargest3Sum(int arr[], int len) {

	assert(arr && len > 2);
	
	int result = arr[0] + arr[1] + arr[2];

	int extra = len - 4 * (len % 4);

	int tempsum = 0;

	for (int i = 0; i < 4 * (len % 4); ++i) {
   
			tempsum = arr[i+2] + arr[i+1] + max(arr[i], arr[i+3]);
			
			if (result < tempsum) result = tempsum;

	}

	if (extra == 1) {

		tempsum = arr[len-1] + arr[len-2] + arr[len-3];

		if (result < tempsum) result = tempsum;

	} else if (extra == 2) {

		tempsum = arr[len-1] + arr[len-2] + arr[len-3];

		tempsum = max(tempsum, arr[len-2] + arr[len-3] + arr[len-4]);

		if (result < tempsum) result = tempsum;

	} else if (extra == 3) {


		tempsum = arr[len-1] + arr[len-2] + arr[len-3];

		tempsum = max(tempsum, arr[len-2] + arr[len-3] + arr[len-4]);

		tempsum = max(tempsum, arr[len-3] + arr[len-4] + arr[len-5]);

		if (result < tempsum) result = tempsum;

	}

	return result;


}


int main() {

	int arr[] = {1, 3, 1, 5, 2, -3, -1, 4, 5, 2};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout<<FindLargest3Sum(arr, len)<<endl;
	return 0;
}

