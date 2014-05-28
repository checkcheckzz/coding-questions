/*
There are are 26 English upper and lower-case letters. Consider the encoding where vowels are mapped to numbers as follows: (a=1, e=5,
i=9, o=15, u=21, y=25 or 0). A vowel sequence is a maximal substring of consecutive vowels. A vowel product is the product of the vowel
encoding of all vowels in a vowel sequence.  The vowel product sum is the sum of the vowel product of all vowel sequences in the string.

A letter in [AEIOUaeiou] is always a vowel. 'y' or 'Y' is a vowel if it is preceded by a consonant; otherwise, it is a consonant. An
ASCII character is either a vowel, a consonant, or a  non-letter. Treat all upper-case letters the same as lower-case letters.

For examples:

"Google Guy" has vowel sequences of "oo", "e", and "u". Its score is 15 * 15 + 5 + 21 = 251.

"Yyyyy" has vowel sequences of "y" and "y". Its score is 25 + 25 = 50.

"myopia" has vowel sequences of "yo" and "ia". Its score is 25 * 15+ 9 * 1 = 384.

"Quietly" has vowel sequences of "uie" and "y". Its score is 21 * 9 * 5 + 25 = 970.

"I'm Feeling Yucky!" has vowel sequences of "I", "ee", "i", "u", and "y". Its score 9 + 5 * 5 + 9 + 21 + 25 = 89.  The first 'Y' in
"Yucky" is preceded by a space (non-letter), so it is not considered a vowel.
*/

/*

solution: define the vowel checking rule correctly. Then just one scan.
O(n) time, O(1) space

*/
#include<iostream>
#include<cctype>
#include<string>
using namespace std;

bool checkBasicVowel(char c) {

   if (c == 'a' || c =='e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I'  ||  c == 'O' ||c == 'U') {
       return true;

   } else {

	   return false;
   }
}

bool CheckVowel(string str, int index) {

    char c = str[index];

    if (CheckBasicVowel(c))
        return true;
    
    if (index == 0)
        return false;
	

    if (c == 'y' || c == 'Y') {

        if(!checkVowel(str, index - 1) && isalpha(str[index-1])) {
			
	      return true;

		} else {

          return false;

		}
   }

   return false;
}


int GetValue(char c) {

    int value = c - 'a' + 1;
    if (value >= 0) return value;
    return c - 'A' + 1;
}


int CalculateVovewlProduct(string str) {
    bool continous = false;

    int result = 0, lastvalue = -1;

    for (int i = 0; i < str.length(); i++) {

        if (checkVowel(str, i)) {


            if (continous) {
                result -= lastvalue;
                lastvalue *= GetValue(str[i]);
                result += lastvalue;

            } else {

               result += GetValue(str[i]);
               lastvalue = GetValue(str[i]);

			}

			continous = true;


       } else {
           
            continous = false;
            lastvalue = 0;
       }
   }
   return result;
}

int main(){

    string str1 = "Google Guy";
    string str2 = "myopia";
    string str3 = "I'm Feeling Yucky!";
    cout<<CalculateVovewlProduct(str1)<<endl;
    cout<<CalculateVovewlProduct(str2)<<endl;
    cout<<CalculateVovewlProduct(str3)<<endl;
    return 0;

}