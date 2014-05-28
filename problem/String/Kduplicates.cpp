/*

There is a kind of string, which duplicates another short string n time. The length of the short
string is at least 2. Given a string, check whether this string belongs to this kind.

For example:

"abcabcabc"  Ture   duplicate abc 3 times
"bcdbcdbcde" False  
"abcdabcd"   True   duplicate abcd 2 times
"xyz"       False   
"aaaaaaaaaa"  False  ths shortest duplicates only has length 1.

*/

/*

solution: 
O(n) best time, O(1) space

*/
#include<iostream>
using namespace std;



bool IsDuplicate(const string str) {

    int strlen = str.size();

    if(strlen < 4) return false;

    int len = 1; //length of the duplicate substring
    int start = 0;
    for (int i = 1; i< strlen; ++i) {

        if (str[start] == str[i]) {

            start++;
            if(start >= len) start = 0; //reach an end of a duplicate substring, back to beginning

        } else { //current duplicate fails, add the duplicate length 

            len++;
            i = len - 1;  //start from len, not O(n) anymore
            start = 0;  //back to beginning
        }

        if (len > strlen / 2) return false;            
    }

    return len != 1 && (strlen % len == 0);

}


int main(){

    const string str1 = "xyzxy";
    const string str2 = "bcdbcdbcde";
    const string str3 = "aaaaaaaa";
    const string str4 = "abcabcabcab";
    const string str5 = "abaaabaa";
    cout<<IsDuplicate(str1)<<endl;
    cout<<IsDuplicate(str2)<<endl;
    cout<<IsDuplicate(str3)<<endl;
    cout<<IsDuplicate(str4)<<endl;
    cout<<IsDuplicate(str5)<<endl;
    return 0;
}

