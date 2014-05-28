/*
Given three arrays, select each number a, b, c from each array to minimize max(a-b,b-c,c-a)
*/

/*
solution: sort three arrays, from the beginning of each array, compare three elements, increase the array index of the smallest element.
O(n+m+l) time, O(1) space
*/

#include<iostream>
#include<cassert>
#include<algorithm>
using namespace std;

int GetMinDiff(int arr[], int arrlen, int barr[], int barrlen, int carr[], int carrlen) {

   assert(arr && arrlen > 0 && barr && barrlen  >0 && carr && carrlen > 0);

   int arriter = 0;
   int barriter = 0;
   int carriter = 0;

   int result = INT_MAX;
   
   while (arriter < arrlen && barriter < barrlen && carriter < carrlen) {
   
	 int curdiff = max(max(abs(arr[arriter] - barr[barriter]), abs(arr[arriter] - carr[carriter])), abs(barr[barriter] - carr[carriter]));
	
	 result = min(curdiff, result);
	 
	 if (res == 0) return 0;

	 if (a[arriter] <= b[barriter] && a[arriter] <= c[carriter]) {
	 
		  arriter++;
		  
	 } else if(b[barriter] <= a[arriter] && b[barriter] <= c[carriter]) {
	 
		  barriter++;
		  
	 } else {
	 
	      carriter++;

         }
   }
   
   return result;
}

int main() {

    int a[] = {92, 13, 25, 26, 31, 31, 50, 52, 52, 58, 58, 69, 71, 87, 96};
    int b[] = {6, 28, 28, 33, 38, 45, 46, 49, 67, 69, 71, 78, 84, 87, 98};
    int c[] = {10, 18, 21, 34, 36, 46, 53, 54, 65, 72, 79, 80, 82, 85, 93};   
    int len = sizeof(a)/sizeof(a[0]);
    cout<<GetMinDiff(a, len, b, len, c, len);
    return 0;
}
