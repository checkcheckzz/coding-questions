/*
Fina an positive integer from 1 to n such that k = a^2 + b^2, where a , b are positve integers.
*/

/*

solution: brute force.

O(num/2) time, O(1) space

*/
#include<iostream>
#include<math.h>
using namespace std;

void FindSquareSum(int num) {

    for (int a = 1, lena = (int)sqrt((double)num); a < lena ;++a) {

        for (int b = 1, lenb = (int)sqrt((double)num); b < lenb && b <= a ;++b) {

            if(a * a + b * b <=num) {

                cout<<"the number is "<<a * a<<"+"<<b * b<<" = "<<a * a + b * b<<endl;

            }

        }

    }
}

int main() {
    
    int num = 16
    FindSquareSum(num);
    return 0;

}