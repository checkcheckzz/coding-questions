/*

Find the rotation distance of a rotated sorted array. 

For examplle: 
input:
4, 5, 6, 1, 2, 3
output:
3
input:
1, 2, 3, 4, 5, 6
output:
0
input:
2, 3, 4, 5, 6, 1
output:
1

*/

/*

solution: Find the maximal difference of consecutive two elements, and record the position.
Pay attention to the situation that new difference is the same as current maximal difference. 
O(n) time, O(1) space

*/

#include <iostream>
using namespace std;

int RotateMinStep(int k, int len) {
  int p = k + 1;
  if (p < len - p) return p;
  return len - p;
}

int RotationDistance(int arr[], int len) {

    if (len == 1) return 0;

    int maxdiff = abs(arr[0] - arr[1]);
    int maxpos = 0;

    for (int i = 1; i < len; ++i) {
  
        int diff = abs(arr[i] - arr[(i + 1) % len]);

        if (diff > maxdiff) {
            maxdiff = diff;
            maxpos = i;
	    } else if (diff == maxdiff) {
            // equals
            int len1 = RotateMinStep(maxpos,len);
            int len2 = RotateMinStep(i, len);

            if (len2 < len1) {
                maxdiff = diff;
                maxpos = i;
            }
        }
    }

    return RotateMinStep(maxpos, len);
}

int main() {

    int arr[] = {4, 5, 6, 1, 2, 3};
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {2, 3, 4, 5, 6, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<RotationDistance(arr, len)<<endl; //3
    cout<<RotationDistance(arr1, len)<<endl; //0
    cout<<RotationDistance(arr2, len)<<endl; //1
    return 0;
}