/*

Given an array of integers where each element points to the index of the next element 
how would you detect the longest cycle in this array.

Note: suppose the element of array is in range[0, n-1], where n is the length of array, then there 
must be at least one cycle. If one element points itself, this particular cycle length is 1.

*/

/*

solution: DFS
O(n) time, O(n) space

*/


#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

void detectLongestCycleInner(int start, int idx, int arr[], vector<bool>& visited, int &len) {
    visited[idx] = true;
    len++;
     
    if (!visited[arr[idx]]) {
     
        detectLongestCycleInner(start, arr[idx], arr, visited, len);
            
    } else {
     
        assert(start != idx);   //a cycle
    }
     
}


/*

Input: array arr[] and len as the length of arr[].
Output: the length of longest cycle.

*/

int DetectLongestCycle(int arr[], int len) {

    int maxlen = 0;
    int curlen = 0;
    vector<bool> visited(n, false);
	
    for (int i = 0; i <len; ++i) {
           
        if (!visited[i]) {
          
            detectLongestCycleInner(i, i, arr, visited, len);
          
            if (curlen > maxlen) {
               maxlen = curlen;
            }
        }
    }

    return maxlen;
}



}

int main() {
    int a[] = {3, 2, 1, 4, 0};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<DetectLongestCycle(a, len)<<endl;
    return 0;
}
