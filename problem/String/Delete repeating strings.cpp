/*
given input as an array of strings. 
Such as: {"apple Orange", "ORANGE apple", "APPLe oRange", "HI There", "THERE
hI"};
return an array of strings. in the above case, will return "APPLe, oRange", 
""THERE hI".

Here are the rules:
1. two strings are the same when words matches(case insensitive) and order 
doesn't matter, so "apple Orange" == "APPLe oRange" == "ORANGE apple".
2. if multiple identical strings exist, only return the one that occurs at 
the last location, so "APPLe oRange" and "THERE hI" will in the result.
3.  the relative order cannot be changed, so we cannot have result as "THERE
hI", "APPLe oRange".

*/

/*

solution: use a set, the key is the ordered lowercase letter of the string. Scan from the end of original
array strings, if the set does not include the key, insert it to the set and to the final vector.
reverse the final vector at last.

O(n*len) time, O(n) space, n is the length of string array, len is the average length of each string.
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<unordered_set>
using namespace std;

string GetKey(string str) {

    string temp = str;

    for (int i = 0; i < str.size(); ++i) {

        if (isupper(temp[i])){

            temp[i] = tolower(temp[i]);

        }
    }
    sort(temp.begin(), temp.end());
    return temp;
}



vector<string> DelReapting(const string str[], int len, unordered_set<string> &mp ) {

    vector<string> res;

	for(int i = len - 1; i >= 0; --i) {

        string key = GetKey(str[i]);
        if (mp.find(key) == mp.end()) {

            mp.insert(key);
            res.push_back(str[i]);
        }

    }

    reverse(res.begin(), res.end());

    return res;

}

int main() {

    string str[5] = {"apple Orange", "ORANGE apple", "APPLe oRange", "HI There", "THERE hI"};
    unordered_set<string> mp;
    vector<string> result = DelReapting(str, 5, mp);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<endl;
    }
    return 0;
}