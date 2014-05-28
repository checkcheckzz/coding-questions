/*

There are n stacks of stones on a playgroud. We want to merge all stones together.
The rule is that you need to merge two adjacent stacks together every time and get a
score the same as the number of stones in the new stack. Please design a 
algorithm to get the maximal and minimal scores after the n stacks are merged to 
one stack.

*/


/*

solution: dynamical programming. Because there is a cycle, we change the cycle to an array num[] by copying the cycle again
to the end of first cycle.
dpMin[i][j] denotes the minimal score by merging stack i to stack j, dpMax[i][j] denotes the maximal score by merging
stack i to stack j.
Transition function:
dpMin[i][j] = min(dpMin[i][j] , dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
dpMax[i][j] = max(dpMax[i][j] , dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
here sum[] is the num[] prefix sum array.
O((2*n)^3) time, O((2n)^2) space
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;
int dpMax[N][N] , dpMin[N][N];



void StoneMinMaxScores(int num[], int len) {

    int sum[N];
    memset(sum , 0 , sizeof(sum));
    for (int i = 1 ; i <= 2 * len ; i++) {
        dpMax[i][i] = dpMin[i][i] = 0;
        sum[i] = sum[i-1] + num[i];
    }

    for (int k = 1 ; k < len ; k++) {
        for (int i = 1 ; i <= 2*len-k ; i++) {
			//k is the interval length
			//i is the interval begin point
			//j is the interval end point
            int j = i+k;
            dpMax[i][j] = INT_MIN;
            dpMin[i][j] = INT_MAX;
            //p is the inner interval points 
            for (int p = i ; p < j ; p++){
                //score equals num[i] + num[i+1] + ... + num[j]			
                int score = sum[j] - sum[i-1];
                dpMax[i][j] = max(dpMax[i][j],dpMax[i][p] + dpMax[p+1][j]+score);
                dpMin[i][j] = min(dpMin[i][j],dpMin[i][p] + dpMin[p+1][j]+score);
            }
        }
    }
    int minSco = INT_MAX;
    int maxSco = INT_MIN;
    for (int i = 1 ; i <= len ; i++) { // note the index range here
        minSco = min(minSco , dpMin[i][i+len-1]); 
        maxSco = max(maxSco , dpMax[i][i+len-1]); 
    }
    cout<<minSco<<" " <<maxSco<<endl;

}

int main(){

    int org[] = {-1, 4, 4, 5, 9}; //does not use index 0
    int len = sizeof(org)/sizeof(org[0]);
    int num[N];
    for (int i = 1; i <=len; i++) {
        num[i] = org[i];
    }
    for (int i = 1; i <=len; i++) {
        num[i+len] = org[i];
    }
        StoneMinMaxScores(num, len);
    return 0;
}


