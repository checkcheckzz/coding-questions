/*
Print all primer factors up to a number.
Note: we only output a repeating primer factor once. 
*/

/*

solution: Print 2 factor, and divide the number as much as possible. From i=3, if
i divides number, print i and divide number by i.At last, print number directly if number is still large than 2.
Note: if we get visited primer factor, we skip it. 
*/


#include <iostream>
using namespace std;


void FindPrimeFactors(unsigned int num) {
    
    int pre = 0;
    while (num%2 == 0) {  
        if (pre != 2) cout<<"2 ";
        num = num/2; 
        pre = 2;
    }

    for (unsigned int i = 3; i*i <= num; i = i+2) {
        while (num%i == 0) {
            if(pre != i) cout<<i<<" ";
            num = num/i; 
            pre = i;
        }
    }
 
    if (num > 2) {
        if (pre != num) cout<<num<<" ";
        pre = num;
    }
}
 

int main() {

    unsigned int num;
    cin>>num; 
    cout<<"The primer factors of "<<num<<" are:"<<endl;
    FindPrimeFactors(num);
    return 0;
}
