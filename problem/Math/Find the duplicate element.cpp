/*

Given a list of integers of length n in the range of 1 to n-1, find the duplicate element (only one duplicate).

For example:
Input: {2,3,1,5,4,6,3}
Output: 3


*/

/*

solution1: use a for loop to compute the sum of the list, then returns sum-(n-1)*n/2. Sum may overflow.
O(n) time, O(1) space

*/

/*

solution2: take the array as a hashtable. The array will be modified.

O(n) time, O(1) space

*/

int FindDuplication(int A[], int n) {

    for (int i = 0; i < n; ++i) {
   
        while (A[i] != i+1) {
	 
        if ( A[ A[i]-1 ] == A[i]) {
	   
            return A[i];
        }  

            swap(A[i], A[ A[i]-1 ]); //swap the element to correct position
        }
    }
}

/*

solution3: sort the array first, check consecutive elements. The array will be modified.
O(nlogn) time, O(1) space
*/

/*

solution4: use XOR.
O(n) time, O(1) space.

*/

int Duplicate(int A[], int n) {
        
    int XOR1 = 1;
    for (int i = 2; i <= n-1; ++i) {
	
          XOR1 = XOR1 ^ i;
    }
    int XOR2 = A[0];
    for(int i = 1;i < n; ++i) {
	
         XOR2 = XOR2 ^ A[i];
    }
    return XOR1 ^ XOR2;
        
}

