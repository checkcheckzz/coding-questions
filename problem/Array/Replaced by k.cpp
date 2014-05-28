/*

Given an unsigned int array with size n，the sum of array equals a，calculate a number k such that the
sum of array becomes b when all numbers in the array greater than k is replaced by k


Given [1,2,5,7,7,8], a = 30, b = 26
k should be 6 because sum of [1,2,5,6,6,6] = 26

*/

/*

solution: sort the array at first(assume it is sorted), then apply binary search. Substract the extra sum at last.
O(nlogn) time, O(1) space
*/

#include<iostream>
#include<cassert>
#include<algorithm>
using namespace std;


int ReplaceNum(int arr[], int len, int b) {

    assert(arr && len > 0 && b >= 0);
    
    int index = -1;
    int cursum = -1;
    int low = 0, high = len-1;
    while (low <= high) {
    
        int mid = low + (high - low)/2;
        int sum = 0;
        for (int i = 0; i < len; i++) {
        
            sum += min(arr[i], arr[mid]); //suppose replace all a[i]>=a[mid] with a[mid]
        }
        if (sum == b) return arr[mid];
        else if(sum > b) {
        
            index = mid;
            cursum = sum;
            high = mid - 1;
            
        } else //sum<b {
        
            low = mid + 1;
        }
     }
	 
     if (index == -1) return  -1; //impossible
     if ((cursum - b) % (len-index) != 0) return -1; //decrease the extra part from a[index]...a[len] evenly 
     return arr[index] - (cursum -b) / (len-index);  //decrease a[index] ...a[len] each by (cursum -b)/(len-index)

  
  return -1;
}

int main() {

    int a[] = {1,2,5,7,7,8};
    cout<<ReplaceNum(a,6,26)<<endl;
    return 0;

}
