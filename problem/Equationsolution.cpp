/*
Given an equation as below: 
a1x1^3+ a2x2^3+ a3x3^3+ a4x4^3+ a5x5^3=0 
The coefficients are given integers from the interval [-30,30]. 
Find the number of solutions (x1, x2, x3, x4, x5) for this equation, where any xi!=0 and xi is in interval [-50,50]

*/


/*

solution: a1x1^3+ a2x2^3+ a3x3^3 = -(a4x4^3+ a5x5^3)
calculate the left side and store the result in a table, then calculate the right side and check its corresponding
counts in the table.
O(n^3) time, O(3*n^4) space, here n is 30.

*/

#include<iostream>
using namespace std;
#define MAX 2430000

int table[MAX * 2 + 400];

int FindSolutions(int coeff[]) {

    int lefteq = 0;
    int righteq = 0;
    int sum = 0;

    for (int  i = -30 ; i <= 30; i++) {

       for ( int j = -30; j <= 30; j++) {

           for ( int k = -30; k <= 30; k++) {

               if ( i != 0 && j != 0 && k != 0) {
                   lefteq = i*i*i*coeff[0] + j*j*j*coeff[1] + k*k*k*coeff[2];
                   lefteq += MAX;
                   table[lefteq]++;

               }
				
          }
      }
   }

   for(int i = -30; i <= 30; i++) {

       for(int j = -30; j <= 30; j++) {

          if( i != 0 && j != 0) {
              righteq = -(i*i*i*coeff[3] + j*j*j*coeff[4]);
              righteq += MAX;
              sum += table[righteq];
		  }
				
	   }
   }

   return sum;

}


int main() {

    int coeff[] = {10, 20, 21, 17,8};
    cout<<FindSolutions(coeff)<<endl;
    return 0;
}