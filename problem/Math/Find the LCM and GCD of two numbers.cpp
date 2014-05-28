/*
Find the LCM and GCD of two numbers
*/

/*

solution: math

*/

#include<iostream>
using namespace std;

int GetGCD(int a, int b) {
    int maxnum = max(a, b);
    int minnum = min(a, b);
 
    // a & b's gcd equals to a & |a-b|'s gcd
    
    while (maxnum % minnum != 0) {
    
        minnum = maxnum % minnum;
    }    
 
    return minnum;
}
 
int GetLCM(int a, int b) {
    int n1 = getGCD(a, b);
    int n2 = a/n1;
    int n3 = b/n1;
 
    return n1*n2*n3;
}

int main() {
    cout<<GetGCD(6,24)<<endl;
    cout<<GetLCM(8,12)<<endl;
    return 0;
}


