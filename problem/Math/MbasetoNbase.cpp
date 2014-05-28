/*

Change a m base number to a n base number.

*/


#include<iostream>
#include<cassert>
#include<string>
using namespace std;

/*
solution1:
A very simple version. 
m base number is first changed to a 10 base number, then the 10 base number is
change to a n base number. 
Issue: the range is limited by the 10 base number, i.e., the int type.
O(n) time, O(1) space
*/

void MbaseToNbase1(char *numbasem, unsigned int m,  char *numbasen, unsigned int n) {

    assert(numbasem && m>0 && numbasen && n>0 );
    int i = 0;
    char c, *p = numbasen;
 
    //change the m base number to a base 10 number
    while (*numbasem != '\0')
        i = i*m + *numbasem++ - '0';
     
    while (i) {
        *p++ = i % n + '0';
        i /= n;
    }
    *p-- = '\0';
 
    //reverse the n base number
    while (p > numbasen) {
        c = *p;
        *p-- = *numbasen;
        *numbasen++ = c;
    }
	
}

/*
solution2:
a complex version which can process big number, we need to transfer
the m base nunber to n base number directly.

*/

int main() {
    char *a = "10111";
    char b[20] = {"           "};
    MbaseToNbase1(a, 2, b, 8);
    cout<<b<<endl;
    return 0;
}

