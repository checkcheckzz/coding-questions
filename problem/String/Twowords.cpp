/*

Given a large amount of words, output all words which can be combined from other two words.

*/

/*

solution: input all the words into a hash table. Iterate each word, and split it to two possible
words, and check whether these two words exist in the hash table.
O(n*len) time, O(n) space, len is the average length of each word

*/

#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

void AllTwoWords(string words[], int len,  unordered_set<string> &mp) {

    for (int i = 0; i < len; ++i) {

        mp.insert(words[i]);

    }
    for (int i = 1 ; i < len; ++i) {

        if (!words[i].empty()){
			
            int wordlen = words[i].length();

            for (int j = 0; j < wordlen-1; ++j) {

                string temp = words[i];

                if (mp.find(temp.substr(0, j)) != mp.end() && mp.find(temp.substr(j, wordlen)) != mp.end()) {

                    cout<<words[i]<<endl;
                    break;
                }

            }

        }

    }

}

int main() {

    string words[9] = {"abv", "tfsdfa", "ab", "v", "tfs", "dfa", "abvtfsdfa", "abtfs", "vab"};
    unordered_set<string> mp;
    AllTwoWords(words, 9,  mp);
    return 0;
}

