/*
Given an array of sorted integers where each one is in the range from 0 to m-1 and m > n,
where n is the length of this array.
Find the smallest number that is missing from the array.
*/

/*
solution: modified binary search. 
O(logn) time, O(1) space
*/

#include<iostream>
using namespace std;

int FindFirstMissing(int arr[], int begin, int end) {
    
    //end+1 is the number larger than the last element of array
    if (begin > end)
      return end + 1;
 
    if (begin != arr[begin]) return begin;
 
    int mid = (begin + end) / 2;
 
    if (arr[mid] > mid) {
        return FindFirstMissing(arr, begin, mid);
    } else {
        return FindFirstMissing(arr, mid + 1, end);
    }
}

int main() {

    int arr[]= {0, 1, 2, 6, 9};
    int arr1[]= {0, 1, 2, 3, 4};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<FindFirstMissing(arr, 0, len-1)<<endl; //3
    cout<<FindFirstMissing(arr1, 0, len-1)<<endl; //5
    return 0;

}