/*
The numeric representation must eliminate 7, for example 6 -> 6 but 7 -> 8 and 17 -> 19 (because 7 and 17 has '7')
so the number should plus 2 which is 17 + 2 = 19.

Given a number in such rule, calculate the original one.
*/
 
 /*
 
 solution: 
 O(d) time, O(1) space, d: the number of digits in the number.
 
 */
 
#include<iostream>
#include<algorithm>
using namespace std;

unsigned int OrignalNumber(unsigned int num) {

    int extra = 0;
    int b = 0;
    int a = 0;
 
    unsigned int temp = num;
    
    while (temp != 0) {
    
        int curdigit = temp % 10; //last digit
        if (curdigit> 7) {
        
            extra += pow((double)10, a) + (curdigit - 1) * b;
            
        }  else  {
        
            extra += curdigit * b;
        
        }
 
        b = pow((double)10, a) + 9 * b; 
        a++;
        temp /= 10; //delete last digit
    }
 
    return num - extra;
}

int main() {

    cout<<OrignalNumber(26)<<endl;
    cout<<OrignalNumber(19)<<endl;
    cout<<OrignalNumber(28)<<endl;
    return 0;
}

