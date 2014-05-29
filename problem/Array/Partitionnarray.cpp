/*

Given an array with integers,  find the index to minimize the difference between 
left part sum and right part sum, not including the index number itself, return the position of the integer.  

*/

/*

solution: Calculate the sum of array. Scan the array, maintain a left sum and right sum, and record the minimal difference.
O(n) time, O(1) space

*/

#include<iostream>
#include<cassert>
using namespace std;

int Partition(int arr[], int len) {

    assert(arr && len >0);
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }
    int pos = -1;
    int diff = INT_MAX;
    int left = 0;
    for (int i = 0; i < len; ++i) {
            
        int right = sum - left - arr[i];
        if (abs(right - left) < diff) {
            pos = i;
            diff = abs(right - left);
        }

        left += arr[i];
    }
    return pos;
}


int main(){

    int arr[]= {1, 5, 7, 12, 10, 11, 7, 5, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<Partition(arr, len)<<endl;
    return 0;
}
