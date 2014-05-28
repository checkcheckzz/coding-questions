/*
Given an array of positive and negative integers, resort it so that you have positives on one end and negatives on the other,
but retain the original order of appearance, do it in-place.

*/

/*
solution: divide&conquer
O(nlogn) time
*/

#include<iostream>
#include <cassert>
#include<algorithm>
using namespace std;

//swap the elements in array from beg to end
void SwapRa(int arr[], int beg, int end) { 
    
    assert(arr && beg <= end);
 
    while (beg < end) {
    
        swap(arr[beg++], arr[end--]);
        
    }    
}
 

void ReSort(int arr[], int len) {
    assert(arr && len > 0);
 
    if (len <= 1) return;
 
    ReSort(arr, len/2);
    ReSort(arr + len/2, len - len/2); 
    
    //here, the numbers have this format: ---- "+++ --" ++++
 
    int lftiter = 0;
    
    while (arr[lftiter] < 0) lftiter++;
    
    int rgtiter = len-1;
    
    while (arr[rgtiter] >= 0) rgtiter--;
     
   
    if (rgtiter <= lftiter) return; //middle part has current order
	
    //swap the middle part
    SwapRa(arr, lftiter, rgtiter);
 
    int begrgt = lftiter;
    
    while (arr[begrgt] < 0) begrgt++;
        
    //swap the two parts to make middle part retain the origin order
    
    SwapRa(arr, lftiter, begrgt-1);
    SwapRa(arr, begrgt, rgtiter);
}

void Print(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
	
        cout<<arr[i]<<",";
    }
    cout<<endl;

}

int main() {

    int a[6] = {1, 3, -7, 8, -1, 4};
    Print(a,6);
    ReSort(a,6);
    Print(a,6);
    return 0;
}

