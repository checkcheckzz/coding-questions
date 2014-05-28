/*
Given a string S and a string T, find the minimum window in S which will 
contain all the characters in T in the orders as it appears in T in 
complexity O(n).

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "ADOBEC"
*/

/*

solution: 
suppose we find string t in string s. dp[i][j] means that the minimal length of finding the substring in T from index j in s from index i.
so, s[i,i+dp[i][j]-1] is the minimal length window we wants. 
O(n*m) time, O(n*m) space
*/

#include<iostream>
#include<string>
using namespace std;
//just for simplicity
int dp[20][20];

void MinWindows(string s, string t) {

    int m = s.size();
    int n = t.size();
    int minindex = -1;
	//assume not match at first
	memset(dp, -1, sizeof(dp));
     
	//always match empty string
    for (int i = 0; i <= m; i++) {
        dp[i][n] = 0;
    }
      
    for (int i = m-1;i >= 0; i--) {
        for (int j = n-1;j >= max(0, n-(m-i)); j--) {
            //match and increase length by one
            if (s[i] == t[j] && dp[i+1][j+1]>=0) {
                dp[i][j] = dp[i+1][j+1]+1;
            //check if previous i position matches
			} else if (dp[i+1][j] >= 0) {
                dp[i][j] = dp[i+1][j]+1;
			}
		}
		//match all chars in t & update minimal length
        if (dp[i][0] >= 0 && (minindex == -1 || dp[i][0] < dp[minindex][0])) {
            minindex = i;
		}
    }

    if (minindex>=0) {
        cout<<"start: "<<minindex<<" ";
        cout<<"len: "<<dp[minindex][0]<<endl;
    }
}


int main() {

    string s("ADOBECODEBANC");
    string t("ABC");
    MinWindows(s, t);
    return 0;

}

