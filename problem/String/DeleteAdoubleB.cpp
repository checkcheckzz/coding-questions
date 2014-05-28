/*
Given a string£¬delete all char A£¬and double all char B.
For example:
Input: ACAABDB
Output: CBBDBB
*/

/*

solution: scan first time from the beginning to remove all 'A' and count the number of B, scan second time from the end to double B.
O(n) time, O(1) space
*/

#include<iostream>
using namespace std;


char *StringRemoveADoubleB(char *str) {
    if (!str) return NULL;

    char *orgiter = str;
    char *newiter = orgiter;
    int countb = 0;
    int len = 0;

	
    while (*orgiter) {

        if (*orgiter == 'B') countb++; // Count B
        if (*orgiter != 'A') {
			*newiter++= *orgiter++;
            len++;
        } else {
            orgiter++;  // Remove A
        }
    }

	
    if (len) {

        orgiter = str+(len+countb); //new string length
        *orgiter = '\0';
        orgiter--;
        newiter--;
        while (newiter != str) {

            if (*newiter == 'B') {
                *orgiter-- = 'B';

			}
            *orgiter-- = *newiter--;
        }
        if (*newiter == 'B') { //the begin of str is B

            *orgiter = 'B';

        }
    }
    return str;
}

int main() {

    char *str1 = "CAABD";
    char *str2 = "ACAABDB";
    char *str3 = "BACAABDBA";
    cout<<StringRemoveADoubleB(str1)<<endl;
    cout<<StringRemoveADoubleB(str2)<<endl;
    cout<<StringRemoveADoubleB(str3)<<endl;
    return 0;
}