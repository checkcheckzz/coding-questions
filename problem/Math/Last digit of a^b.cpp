/*

Calculate the last digit of a^b, where a,b are positive. Use map to store the last digit.
O(logb) time, O(10) space

*/

#include<iostream>
#include<map>
#include<math.h>
using namespace std;

unsigned int LastDigit(unsigned int a, unsigned int b, map<unsigned int, unsigned int> &mp){

    if (a == 1) return 1;
    unsigned int digit = a %10;
    digit = mp[a]; //a^2;

    unsigned int time = 2;
    for (; time * 2 <= b; time = time * 2){

        digit = mp[digit];
    }
   
   time = time / 2;

   unsigned int extratime = b - time * 2;

   digit = (digit * (int)pow((double)a, (int)extratime)) % 10;
  

   return digit;
}


int main(){
	
    map<unsigned int, unsigned int> mp;
    mp[1]=1;
    mp[2]=4;
    mp[3]=9;
    mp[4]=6;
    mp[5]=5;
    mp[6]=6;
    mp[7]=9;
    mp[8]=4;
    mp[9]=1;

    cout<<LastDigit(2, 35, mp)<<endl;
    return 0;
}