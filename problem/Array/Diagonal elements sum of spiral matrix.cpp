/*
Diagonal elements sum of spiral matrix

For example: 
Input:
25 24 23 22 21 
10 9  8  7 20 
11 2  1  6 19 
12 3  4  5 18 
13 14 15 16 17 

Output: 
45 (21 + 7 + 1 + 3 + 13) 

*/

/*

solution1: scan the matrix and count the sum of diagonal elements.

O(n*n) time, O(1) space

*/

int DiagSum1(int maxtrixdim) {
   if (maxtrixdim < 1) return 0;
   int curelement = (maxtrixdim - 1) * maxtrixdim + 1;
   int result = curelement;
   while (--maxtrixdim > 0) {
   
     curelement -= (maxtrixdim + maxtrixdim);
     result += curelement;
   }
   
   return result;
}

/*

solution2: consider the special structure of the matrix

f(n) = 4[(n^2)] – 6(n-1) + f(n-2)  
source: https://www.geeksforgeeks.org/sum-diagonals-spiral-odd-order-square-matrix/

O(n) time, O(1) space

*/

int DiagSum2(int n) 
{ 
    if (n == 1) 
        return 1; 
  
    // as order should be only odd 
    // we should pass only odd-integers 
    return (4*n*n - 6*n + 6 + DiagSum2(n-2)); 
} 



