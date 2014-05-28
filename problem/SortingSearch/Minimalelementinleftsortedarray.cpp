/*

Get the minimum number of a roatated sorted array

*/

/*

solution:  use two pointers beg and end. end pointer points to one element in the second increasing subarray,
beg pointer points to one element in the first increasing subarray. Let mid =(beg+end)/2, if a[mid] is in the first 
increasing subarray, smallest element should be after a[mid], or if a[mid] is in the second increasing subarray,
smallest element should be before a[mid]. We can skip half array. At last, end points to the first element in the second increasing subarray, 
beg points to the last element in the first increasing subarray. The element end points to is the result we want. 

O(logn) time, O(1)
*/

#include<iostream>
#include<cassert>
using namespace std;

int MinNumberRotatedArray(int arr[], int len) {

    assert(arr && len > 0);
        
    int beg = 0;
    int end = len - 1;
    int mid = beg;
    while (arr[beg] >= arr[end]) {
		//at last, end points to the first element in the second increasing subarray
		//beg points to the last element in the first increasing subarray
        if (end - beg == 1) {
            mid = end;
            break;
        }
        mid = (beg + end) / 2;
		//smallest element should be after arr[mid]
        if (arr[mid] >= arr[beg]) {
            beg = mid;
		} else if (arr[mid] <= arr[end]) {
            end = mid;
		}
    }
 
    return arr[mid];
}
int main() {   

    int arr[]={3,4,5,1,2};
    int arr1[]={1,2,3,4,5};
    int arr2[]={3,4,5,1,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<MinNumberRotatedArray(arr,len)<<endl;
    cout<<MinNumberRotatedArray(arr1,len)<<endl;
    cout<<MinNumberRotatedArray(arr2,len)<<endl;
    return 0;
}
