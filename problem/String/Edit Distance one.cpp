/*
Given two strings, check whether once string can be transformed to another string
by insert, delete , or replace one char.

For example:
Input     Output
cat cast  True    // by insert
cat at    True      // by delete
cat cot   True    // by replace
cat dog   False   // no way
cat cat   False  // the same, no way

*/

/*

solution: just scan once.
O(n) time, O(1) space

*/

#include<iostream>
#include<string>
using namespace std;

bool TransformString(string str1, string str2) {

    int len1 = str1.size();
    int len2 = str2.size();

    if (abs(len1 - len2) > 1) return false;

    if (len1 > len2) return TransformString(str2, str1);

	//replace	
    if (len1 == len2) {

        int countdiff = 0;

        for (int i = 0 ; i < len1; ++i) {

            if (str1[i] != str2[i]) countdiff++;
        }

        return countdiff ==1;

    } else { //insert

        int i =0, j =0;

        while (i < len1 && str1[i] == str2[j]) {
            i++;
            j++;
        }
        j++;
        while (i < len1 && str1[i] == str2[j]){
            i++;
            j++;
        }

        return i == len1;
	}
}

int main() {

    string str1 = "cat", str2 = "cot";
    string str3 = "cat", str4 = "cat";
    string str5 = "cat", str6 = "cast";
    string str7 = "cat", str8 = "at";
    cout<<TransformString(str1, str2)<<endl;
    cout<<TransformString(str3, str4)<<endl;
    cout<<TransformString(str5, str6)<<endl;
    cout<<TransformString(str7, str8)<<endl;
    return 0;

}