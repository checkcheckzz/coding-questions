/*

 Given an integer array arr, find the maximal a[i] such that a[i]=a[x]+a[y].
 
*/

/*

solution: sort&binary search
O(nlogn) time, O(1) space

*/

#include<iostream>
#include<cassert>
#include<algorithm>
using namespace std;

bool TwoSum(int arr[], int len, int skipindex) {

    assert(arr && len > 0 && skipindex >= 0 && skipindex < len);
 
    int beg = 0;
    int end = len-1;
    
    while (beg < end) {
        
        if (beg == skipindex) {
        
            beg++;
            
        } else if (end == skipindex) {
        
            end--;
            
        } else if (arr[beg] + arr[end] == arr[skipindex]) {
        
            return true;
            
        } else if (arr[beg] + arr[end] < arr[skipindex]) {
        
            beg++;
            
        } else { 
        
          end--;
        }  
    }
 
    return false;
}
 
bool FindMaxItem(int arr[], int len, int& result) {
    assert(arr && len > 0);
 
    sort(arr, arr+len);
 
    bool found = false;
    int maxelement = INT_MIN;
    
    for (int i = 0; i < len; ++i) {
    
        if (TwoSum(arr, len, i)) {
        
            found = true;
            maxelement = max(maxelement, arr[i]);
        }
    }
 
    if (found) result = maxelement;
 
    return found;
}

int main() {

    int arr[] = {1,3,2,4,5,7,-3,-2,13};
    int len = sizeof(arr)/sizeof(arr[0]);
    int res = -10000;
    FindMaxItem(arr, len, res);
    cout<<res<<endl;
    return 0;
}
