/*
given an array, get the length of first subarray that sums to 0
*/

/*
solution: note if sum[i...j] == 0, then sum[0...i-1] == sum[0 ... j]
O(n) time, O(n) space

*/

#include<iostream>
#include<cassert>
#include<unsorted_map>
using namespace std;

int FirstContZero(int arr[], int len) {
    assert(arr && len > 0);
 
    unsorted_map<int, int> mp;
    int sum = arr[0];
    int result = (sum == 0 ? 1 : 0);
 
    for (int i = 1; i < len; ++i) {
    
        sum += arr[i];
        if (mp.find(sum) == mp.end()) {  //does not find Sum in mp
        
            mp[sum] = i;
        
        } else {
			
            result = max(result, i - mp[sum]);
        }    
    }
 
    return result;
}
int main() {

    int arr[6] = {1, -1, 2, -2, 1, 0};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<FirstContZero(arr, len)<<endl;
    return 0;

}
