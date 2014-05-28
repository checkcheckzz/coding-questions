/*

Given a string including 1, 0 and ?, return all matching strings.
Char ? can match 0 and 1.

For example:

Input : 1?? 
Output: {100, 101, 110, 111}.

*/

/*

solution1: backtracking. 
O(k^2*(n-k)) time, O(1) space, k is the number of ? in string with size n.
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;

void GenerateMatchStringInner(string s, int index, vector<string> &result) {
    if (index == s.size()) {
        result.push_back(s);
        return;
    }
    if (s[index] == '?') {
        string temp1 = s;
        temp1[index] = '0';
        GenerateMatchStringInner(temp1, index+1, result);
        
        string temp2 = s;
        temp2[index] = '1';
        GenerateMatchStringInner(temp2, index+1, result);
    } else {
        GenerateMatchStringInner(s, index+1, result);
    }
}

vector<string> GenerateMatchString(const string &s) {
    int n = s.size();
    vector<string> result;
    if ( n == 0) {
        return result;
    }
    GenerateMatchStringInner(s, 0, result);
    return result;
}



int main() {

    string str ="1??";
    vector<string> result = GenerateMatchString(str);
    for (size_t i = 0; i < result.size(); ++i) {

        cout<<result[i]<<endl;
    }
    return 0;
}

/*

Solution2: iterative method using stack


*/


