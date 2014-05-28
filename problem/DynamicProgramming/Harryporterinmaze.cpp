/*
There is a two dimensional grid. Suppose you are harry potter, standing at the top left corner. Your
target is the botton right corner. You can only move right or down, one step per move.
The grid includes positive and negative number. You have a blood value.
When you meet a positive value, the blood value increases as the corresponding vaue, when you 
meet a negative value,  the blood value decrease as the corresponding number. 
When you blood value is smaller or equal to zero, you will die. Please calcuate a
minimal blood value such that you can find at least one way from top left corner to botton right corner.

*/

/*

solution: dynamic programming.

Transition function:
f(i, j) is the minimal value needed up to (i, j)
We move backward from botton right corner to left top corner

f(m, n) = 0

f(i, j) = min(
  max(f(i+1, j) - grid(i+1,j), 0),
  max(f(i, j+1) - grid(i, j+1), 0)
)

Note the value at left top corner does not count.
O(m*n) time, O(m*n) space

*/
#include<iostream>
#include<algorithm>
using namespace std;
const int K = 20;
//row size
const int m = 5;
//column size
const int n = 5;
int dp[K][K];

int MinimalBlood(const int grid[m][n]) {

    dp[m-1][n-1] = 0;
    for (int i = m-2; i >= 0; i--)
        dp[i][n-1] = max(dp[i+1][n-1]-grid[i+1][n-1], 0);
    for (int j = n-2; j >= 0; j--)
        dp[m-1][j] = max(dp[m-1][j+1]-grid[m-1][j+1], 0);
	for (int i= m-2; i >= 0; i--) {
		for (int j = n-2; j >= 0; j--) {

			dp[i][j] = min(max(dp[i+1][j]-grid[i+1][j], 0), max(dp[i][j+1]-grid[i][j+1], 0));
		}
	}
    return dp[0][0];

}

int main() {

    const int grid[m][n] = {{0, -2, 2, 1, 0},
                            {-2, -3, -2, 1, 2},
                            {-2, -1, -1, -1, -1},
                            {-3, -3, 2, 1, -2},
                            {1, 2, -3, -1, 1}};

    cout<<MinimalBlood(grid)<<endl;
    return 0;
}
