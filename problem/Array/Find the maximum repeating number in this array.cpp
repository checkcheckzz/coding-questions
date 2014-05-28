/*

Given an array of size n, the array contains numbers in range from 0 to k-1 where k is a positive integer
and k <= n. Find the maximum repeating number in this array.

For example, let k be 10 the given array be arr[] = {1, 2, 2,2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3}, the maximum 
repeating number would be 2. 

Expected time complexity is O(n) and extra space allowed is O(1). Modifications to array are allowed，
but the original array should be recovered at the end.

*/

/*

solution: For each a[i], add N to a[a[i]%N], a[i]%N is the orignal number, a[i]/N is the number of a[i] occurance.
At last, recover the array.
O(n) time, O(1) space

*/


#include<iostream>
using namespace std;

int MaxRepeat(int arr[], int len) {

    for (int i = 0; i < len; i++) {
    
         int num = arr[i]%len;
         arr[num] += len;
    }
    
    int result = -1;
    int maxcount = 1;
	
    for (int i = 0; i <len; i++) {
    
        if (arr[i]/len > maxcount) {  
            maxcount = arr[i]/len;
            result = i;        
        }
    }
   
    for (int i = 0; i < len; i++) {
    
            arr[i] %= len;
    }

    return result;
	 
}

int main() {
    int arr[]={1, 3, 3, 2, 0, 2, 0, 2, 3, 8, 2, 9, 2, 3};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<MaxRepeat(arr, len)<<endl;
    return 0;
}
