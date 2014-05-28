/*

Check whether a number is a happy number, and print the first k happy numbers from this number.

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers, while those that do not end in 1 are unhappy numbers.

If a number is happy, then all members of its sequence are happy; if a number is unhappy, all members of the sequence are unhappy.


*/

/*

solution:  if we get 1，return true, cache the middle number, if we get previous visited number, 
return false (because a cycle occurs, and you can't get to 1 forever.)

Proof for the sequence must get smaller.
Suppose the number gets to n digits, next number is less than

9^2 * n = 81 * n 

this is strictly less than the number itself, which is greater than
10^(n - 1)
when n gets greater or equal than 4

so the number will decrease after operation

no possible to overflow

*/
#include<iostream>
#include<set>
using namespace std;

int SumDigits(int num) {

    int sum = 0;
    while (num) {

        int digit = num % 10;
        num = num / 10;
        sum += digit * digit;
    }

    return sum;
}

bool IsHappyNum(int num, set<int> &st ) {

    while (num > 1 && st.find(num) == st.end()) {

        st.insert(num);
        num = SumDigits(num);

    }

    if (num == 1) return true;

    return false;


}

void PrintFirstk(int num, int k) { 

    set<int> stt;
    int count = 0;
    while (count < k) {
        if (IsHappyNum(num, stt)) { 
            count++;
            cout<<num<<endl;
        }
        
        num++;
        stt.clear();
    }


}

int main() {

    int num;
    cin>>num;

    set<int> st;
    bool res = IsHappyNum(num, st);
    if (res) {
        cout<<num<<" is a happy number"<<endl;
    } else {
        cout<<num<<" is not a happy number"<<endl;
    }
    int k = 8;
    cout<<"The next " << k<<" happy number from "<<num<<" is:"<<endl;
    PrintFirstk(num, k);

    return 0;

}
