/*

25 24 23 22 21 
10 9  8  7 20 
11 2  1  6 19 
12 3  4  5 18 
13 14 15 16 17 

Starting with the number 1 and moving to the right in a counter-clockwise 
direction in the 5 by 5 spiral matrix as above, sum the diagonal elements.

for example 21 + 7 + 1 + 3 + 13 

*/

/*

solution1: scan the matrix and count the sum of diagonal elements.

O(n*n) time, O(1) space

*/

/*

solution2: consider the special structure of the matrix

O(n) time, O(1) space

*/

int diagSum(int maxtrixdim) {
   if (maxtrixdim < 1) return 0;
   int curelement = (maxtrixdim - 1) * maxtrixdim + 1;
   int result = curelement;
   while (--maxtrixdim > 0) {
   
     curelement -= (maxtrixdim + maxtrixdim);
     result += curelement;
   }
   
   return result;
}

