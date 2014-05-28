/*

Given a string, find the longest substring containing just two unique chars.

*/

/*

solution: use two pointers as a sliding window to scan the string, use a map record the number of unique chars in the 
substring. Update the record in the map when the second pointer increases, erase the record in the map when
the first pointer increases. Update and record the start position and length of the substring. 
O(n) time, O(n) space

*/

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

string LongestSubstringWithTwoUniqueChars(string &s) {
        if(s.size() <= 2) return s;

        size_t max_start = 0;
        size_t max_len = 2;

        size_t i = 0; //begin of a substring
        size_t j = 0; //end of a substring

        unordered_map<char, int> mp;

        while (i <= j && j< s.size()) {

            while (mp.size() <= 2 && j < s.size()) {

                if (mp.count(s[j]) == 0) {
                    mp[s[j]] = 1;
				} else {

                    ++mp[s[j]];
				}
                if (mp.size() <= 2 && (j-i+1) > max_len) { //update the max_len if necessary

                    max_start = i;
                    max_len = j-i+1;
                }
                ++j;
            }

            if (j == s.size()) return s.substr(max_start, max_len);

            if (mp[s[i]] == 1) { //erase the record of s[i] in mp

                mp.erase(s[i]);

			} else {

                --mp[s[i]];
			}
            ++i;
        }

        return s;
}

int main() {


	string str1 = "abcd";
	string str2 = "abbccd";
	string str3 = "abbccddd";

	cout<<LongestSubstringWithTwoUniqueChars(str1)<<endl;
	cout<<LongestSubstringWithTwoUniqueChars(str2)<<endl;
	cout<<LongestSubstringWithTwoUniqueChars(str3)<<endl;

	return 0;

}
