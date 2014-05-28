/*
Given an integer array, calculate the maximal product subarray. Suppose a[]={3,-4,-5,6,-2},
the maximal product should be 360, i.e., 3*(-4)*(-5)*6=360.

*/
/*
solution: dynamic programming
let Max[i] denotes the maximal product of subarray with a[i] as the last element, and Min[i] denotes the minimal product of subarray with a[i] as the last element, 
the update function is:

Max[i]=max{a[i], Max[i-1]*a[i], Min[i-1]*a[i]};
Min[i]=min{a[i], Max[i-1]*a[i], Min[i-1]*a[i]};

O(n) time, O(1) space

*/

#include<iostream>
#include<algorithm>
using namespace std;

int MaxProductSubarray(int arr[], int len) {  
    int minsofar = arr[0], maxsofar = arr[0], result = arr[0];  
    
    for (int i = 1; i < len; ++i) {
    
       int maxhere = max(max(maxsofar * arr[i], minsofar * arr[i]), arr[i]);  
       int minhere = min(min(maxsofar * arr[i], minsofar * arr[i]), arr[i]);  
       maxsofar = maxhere, minsofar = minhere;  
       if (result < maxsofar)  result = maxsofar;  
    }  

    return result;  
}  


int main() {

    int a[5] = {3,-4,-5,6,-2};
    cout<<MaxProductSubarray(a,5)<<endl;
    return 0;
}
