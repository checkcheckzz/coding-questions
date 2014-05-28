/*

Find the longest substring which begins and ends with unique characters. 

*/

/*

solution: use two pointers as sliding window of the substring. The end pointer record the number of chars in the map,
the begin pointer decrease the count of a char in map until the count reaches 1. Update the maximal substring length and start position
if necessary. At last, return the substring from start with maximial length.
O(n) time, O(n) space

*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string Longestsubstringtwounique(const string str) {

    int len = str.size();
    int i = 0, j = 0;
    int maxstart = 0, maxlength = 0;
    unordered_map<char, int> mp;

    while (j < len) {

        if (mp.find(str[j]) == mp.end()) {

            mp[str[j]] = 1;

        } else {

            mp[str[j]]++;
			  
        }
	 
        char tmp = str[i];
        while (i <j && mp[tmp] > 1) {

            --mp[tmp];

            tmp =  str[++i];

        }

        if (i < j && mp[tmp] == 1 && mp[str[j]] == 1 && j - i >= maxlength) {
            maxstart = i;
            maxlength = j - i + 1;
        }
        ++j;

    }

    return str.substr(maxstart, maxlength);
}


int main() {
	
    const string str1 = "a";
    const string str2 = "abc";
    const string str3 = "abbc";
    const string str4 = "bcccccaaacc";

    cout<<Longestsubstringtwounique(str1)<<endl;
    cout<<Longestsubstringtwounique(str2)<<endl;
    cout<<Longestsubstringtwounique(str3)<<endl;
    cout<<Longestsubstringtwounique(str4)<<endl;
    return 0;

}
