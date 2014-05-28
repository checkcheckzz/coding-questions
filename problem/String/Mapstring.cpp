/*

Two words are called isomorphic if the letters in one word can be mapped to get the second word.

Mapping a letter means replacing all occurrences of it with another letter while the ordering of the letters remains unchanged.

No two letters may map to the same letter, but a letter may map to itself.

Given two words as strings, check if they are isomorphic.

For example, 

given "foo", "app"; returns true we can map f -> a and o->p
given "bar", "foo"; returns false we can't map both 'a' and 'r' to 'o'
given "ab", "ca"; returns true we can map 'a' -> 'b' and 'c' -> 'a'


*/

/*

solution; use two maps to record the map relation. 
O(n) time, O(n) space
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool CheckIsomorphicString(string str1, string str2) {

	if(str1.size() != str2.size()) return false;
	unordered_map<char, char>mp12;
	unordered_map<char, char>mp21;
	for (size_t i = 0; i < str1.size(); ++i) {

		char char1 = str1[i];
		char char2 = str2[i];
		if (mp12.find(char1) !=  mp12.end()) {

            if (mp12[char1] != char2) return false;

        }

		if (mp21.find(char2) !=  mp21.end()) {

            if (mp21[char2] != char1) return false;
        }

		mp12[char1] =  char2;
		mp21[char2] =  char1;

	}
	return true;

}




int main() {

	string str1 = "foo";
	string str2 = "app";
	string str3 = "bar";
	string str4 = "foo";
	string str5 = "ab";
	string str6 = "ca";
	cout<<CheckIsomorphicString(str1, str2)<<endl;
	cout<<CheckIsomorphicString(str3, str4)<<endl;
	cout<<CheckIsomorphicString(str5, str6)<<endl;
	return 0;

}

