/*

Spell out an integer number in English.
For example:
Input: 1000234
Output: One Thousand, Two Hundred and Thirty Four
Note: support negative integer.
*/


/*

solution: process the number by three digits one time, add proper big unit between those digits.
For each three digits, consider different situations. 

*/

#include <iostream>
#include <string>
using namespace std;


string lastdigit[10] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
string allteen[10] = { "", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
string allten[10] = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
string more[6] = { "", "Thousand", "Million", "Billion", "Trillion", "Quadrillion" };

string UnderHundred(int num) {
    string output = "";

    if (num >= 100) {
        output += lastdigit[num/100] + " Hundred ";
        num %= 100;
    }

    if (num >= 11 && num <= 19) { 
        output += allteen[num-10] + " ";
    } else if (num >= 20 || num == 10) {
        output += allten[num/10] + " ";
        num %= 10;
    }

    if (num >= 1 && num <= 9) {
        output += lastdigit[num] + " ";
    }

    return output;
}

string TranslateNumber(long long num) {
    if (num == 0) {
        return "Zero";
    } else if ( num < 0) {
        return "Negative " + TranslateNumber(-1 * num);
    }
    int index = 0;
    string output = "";

    while (num > 0) {
        if (num % 1000 != 0) {
            output = UnderHundred(num % 1000) + more[index] + " " + output;
        }
        num /= 1000;
        ++index;
    }

    return output;
}

int main() {

    cout<<"Input the number: ";
    long long num;
    cin>>num;
    cout<<TranslateNumber(num)<<endl;
    return 0;
}