/*

Give a bunch of words and a string pattern containing ?, which can match any char.
Return the matched words. 

*/


/*

solution: just scan the words once to match the pattern one by one.
O(n) time, O(1) space

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool CheckMatch(string str1, string str2) {

   if (str1.size() != str2.size()) {
      return false;
   }

   for (size_t i = 0; i < str1.size(); i++) {

       if (str2[i] == '?')  continue;

       if (str2[i] != str1[i]) return false;
   }
   
   return true;
}

vector<string> WordsMatch(vector<string> &words, string pattern) {

  vector<string> res;
  for (size_t i = 0 ; i < words.size(); i++) {

    if (CheckMatch(words[i], pattern)) {

       res.push_back(words[i]);

    }
  }
  return res;
}

int main(){

    vector<string> words;
    words.push_back("rbadd");
    words.push_back("rb c ");
    words.push_back("rbfw ");
    words.push_back("rb ca");
    words.push_back("rbfce");
    string pattern = "rb?c?";
    vector<string> result = WordsMatch(words, pattern);
    for(size_t i =0; i < result.size(); ++i) {
        cout<<result[i]<<endl;
    }
    return 0;
}

