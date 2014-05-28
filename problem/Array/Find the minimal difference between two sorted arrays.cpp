/*

Find the minimal difference between two sorted arrays elements

*/

/*
solution: compare the elements, and increase the index of the smaller array
O(m+n) time, O(1) space
*/

#include<iostream>
#include<cassert>
using namespace std;

int MinDiff(int arrA[],int arrAlen, int arrB[], int arrBlen) {

   assert(arrA && arrAlen > 0 && arrB && arrBlen > 0);

   int arrAiter = 0;
   int arrBiter = 0;

   int result = INT_MAX;
   
   while (arrAiter < arrAlen && arrBiter < arrBlen) {
   
      int diff = abs(arrA[i]-arrB[j]);
      
      result = min(diff,result);
      
      if (result == 0) return 0;
      
      if (arrA[arrAiter] > arrB[arrBiter]) {
      
         arrBiter++;
         
      } else {
      
        arrAiter++;
        
      }
   }
   
   return result;
}

int main() {

  int a[2] = {0,3};
  int b[3] = {2,7,9};
  cout<<MinDiff(a,2,b,3)<<endl;
  return 0;

}
