/*

Given a sorted integer array and a specific integer, find the first position of that integer. 
Array contains duplicates.

*/
 
/*
solution: binary search

O(logn) time, O(1) space

*/


int GetFirstPosition(int arr[], int len, int target) {
    assert(arr && len > 0);
 
    int beg = 0;
    int end = n-1;
    
    while (beg <= end) {
    
        int mid = beg + (end-beg)/2;
 
        if (arr[mid] == target && (0 == mid || arr[mid-1] != target)) {
        
            return mid;
            
        } else if (arr[mid] >= target) {
        
            end = mid - 1;
            
        }  else {
        
            beg = mid + 1;
        }    
    }
 
    return -1;
}
