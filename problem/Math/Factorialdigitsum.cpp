/*

Sum the digits of a number's factorial.

For example:
Input: 10
Output: 27 (27 = 3+6+2+8+8+0+0, 10£¡= 3628800)

*/

/*

solution: we need to consider the big number issue.
O(n!) time, O(d) space, d is the length of factorial length

if we do not consider the big number issue, then O(n) time, O(1) space.
*/

#include<iostream>
#include<cassert>
#include<string>
using namespace std;

string Multiply(string num1, string num2) {
        int N = num1.length(), M = num2.length();
        string res(N+M, '0');
        for (int i = N - 1; i >= 0; --i) {
            int carry = 0;
            int j;
            for (j = M - 1; j >= 0; --j) {
                int sum = carry + (res[i+j+1] - '0') + 
                          (num1[i] - '0') * (num2[j] - '0');
                res[i+j+1] = sum % 10 + '0';
                carry = sum / 10;
            }
            res[i+j+1] += carry;
        }
        while (res.length() > 1 && res[0] == '0') {
            res.erase(res.begin());
        }			
        return res;
}

string FactorialDigitSumInner(string num){
	  	  
    int iter = 0;
    int temp = 0;
    while (iter < num.length()) {
        temp += temp * 10 + num[iter]-'0';
        iter++;
    }
	  
    if (temp == 0) return "1";
    temp --;
    char p[32]; 
    itoa(temp, p, 10);
    string numdecrease = p;
    return  Multiply(num, FactorialDigitSumInner(numdecrease));
}

int FactorialDigitSum(int num){

    assert(num > 0);
    char p[32];
    itoa(num, p, 10);
    string numstr = p;
    string result = FactorialDigitSumInner(numstr);
    int iter = 0;
    int sum = 0;
    while (iter < result.length()) {

        sum += result[iter] - '0';
        iter++;
	}
    return sum;
}

int main() {

    cout<<FactorialDigitSum(7)<<endl;
    return 0;
}
