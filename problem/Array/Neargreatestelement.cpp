/*

Given an array, print the Next Greater Element (NGE) for every element. 

The Next greater Element for an element x is the first greater element on the right side of x in array. 
Elements for which no greater element exist, consider next greater element as -1.

For example:

Input: 11, 13, 21, 3
output: 12, 21, -1, -1
*/

/*

solution: scan the array from right to left. Update current next greater element accordiing to right side original element
and next greater element. 
O(n) time, O(1) space
*/
#include<iostream>
#include<algorithm>
using namespace std;

void NextGreaterElement(int arr[], int len, int result[]) {

    if (len <= 0) return;

	for(int i = len -2; i >= 0; --i){

		int maxtwo = max(result[i+1], arr[i+1]);
		if (maxtwo <= arr[i]) {

			result[i] = -1;

		} else {

			if (arr[i+1] > arr[i]) {

				result[i] = arr[i];

             } else if (result[i+1] > arr[i] && arr[i+1] <= arr[i]){

				 result[i] = result[i+1];

			}

		}

	}

}

int main() {
  
    int arr[]= {11, 13, 21, 3};
    int len = sizeof(arr)/sizeof(arr[0]);
    int result[] = {-1, -1, -1, -1};
    NextGreaterElement(arr, len, result);
    for (int i = 0; i< len; ++i) {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}