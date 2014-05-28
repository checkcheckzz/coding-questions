/*

Implement string getDecimal(int a, int b). For example input a =2 and b=5,  output 0.4 = 2/5, 
, if input a =1, b=6,output 0.1(6) = 1/6 = 0.16666666666666666666666666...

*/

/*

solution: use a map to record the possible repeating digits length (as value) and number (as key).
O(r) time, r is the repeating part length
*/
#include<iostream>
#include<map>
#include<string>
using namespace std;

string GetDecimals(int A, int B) {

    //assume A < B
    string integer = "0" + A/B; 
    long long rest = A % B;
    map<int, int> remain;
    string result = "";
    string d = "";
    while (1) {
        remain[rest] = d.length();
        rest *= 10;
        d += '0' + rest / B;
        rest %= B;
        if (!rest) {
            return integer + "." + d;
        }
        if (remain.count(rest)) { //repeating digit occurs
            break;
        }
    }
    int start = remain[rest]; //repeating digits length
    if (start != 0) {
        result += string(d, 0, start);
    }
    result += "(" + string(d, start, d.length() - start) + ")";
    return integer + "." +result;
}

int main () {

    cout<<GetDecimals(2,4)<<endl;
    cout<<GetDecimals(1,6)<<endl;
    return 0;
}
