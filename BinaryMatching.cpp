/*

Given a string including 1, 0 and ?, return all matching strings.
Char ? can match 0 and 1.

For example:

input : 1?? 
output: {100, 101, 110, 111}.

*/

/*

solution: backtracking. 
O(k^2*(n-k)) time, O(1) space, k is the number of ? in string with size n.
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;

void generateMatchStringInner(string s, int index, vector<string> &result) {
    if (index == s.size()) {
        result.push_back(s);
        return;
    }
    if (s[index] == '?') {
        string temp1 = s;
        temp1[index] = '0';
        generateMatchStringInner(temp1, index+1, result);
        
        string temp2 = s;
        temp2[index] = '1';
        generateMatchStringInner(temp2, index+1, result);
    } else {
        generateMatchStringInner(s, index+1, result);
    }
}

vector<string> generateMatchString(const string &s) {
    int n = s.size();
    vector<string> result;
    if ( n == 0) {
        return result;
    }
    generateMatchStringInner(s, 0, result);
    return result;
}



int main() {

    string str ="1??";
    vector<string> result = generateMatchString(str);
    for (size_t i = 0; i < result.size(); ++i) {

        cout<<result[i]<<endl;
    }
    return 0;
}