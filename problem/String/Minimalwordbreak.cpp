/*
Given a consecutive string without space and a dictionary, 
find the word break way with minimal number of words.
For example:

"applepie" -> "apple pie" 

*/

/*
solution: dp[i] denotes the next word starting position from index i in string.
Scan from string right, find the next word as long as possible, and update dp[i].
O(n) time, O(n) space
*/

#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

string MinimalWordBreak(string text, set<string> dict) {

    int n = text.size();
    int *dp = new int[n+1];
    memset(dp, 0, sizeof(dp));
    dp[n] = n;
        
    for (int i = n-1;i >= 0;i--) {

        int j = i + 1;
            
        while(j <= n && (dict.find(text.substr(i,j)) != dict.end() || dp[j]==0)) j++;
            
        if(j <= n) dp[i] = j;
    }
    //can't break the text        
    if(dp[0] == 0) return "";
        
    string sentence;
    int i = 0;
    while(i < n) {
        sentence.append(text.substr(i,dp[i]) + " ");
        i = dp[i];
    }
        
    return sentence;
}

