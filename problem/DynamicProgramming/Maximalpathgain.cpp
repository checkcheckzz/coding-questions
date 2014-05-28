/*

Given a m*n gird, each grid has an non negative amount of money. Two persons starts from the top left corner (0, 0),
they can only move right and down, whenever they move to a new grid, they get the money, the destination is the bottom right corner(m, n).
Find the maximal amount of money they can get together. Note: the start and end grid is not counted.

*/

/*

solutuion: two-dimensional dynamic programming.

Let dp[ k ][ i ][ j ] denotes the maximal collection when at the kth step£¬first person is at row i£¬second person is at row j, i.e.,
first person is at grid (i,k-j), second person is at grid (j,k-j).

At the k-1 the step:
f [ k - 1 ][ i ][ j ]: both person move down
f [ k - 1 ][ i - 1 ][ j ]: first person moves right£¬second person moves down
f [ k - 1 ][ i ][ j-1 ]: first person moves down£¬second person moves right
f [ k - 1 ][ i-1 ][ j-1 ]: both person move right


Transition function:

f [ k ][ i ][ j ] = max { f [ k - 1 ][ i - 1 ][ j ], f [ k - 1 ][ i ][ j - 1 ], f [ k - 1 ][ i ][ j ], f [ k - 1 ][ i - 1 ][ j - 1 ] } + map[ i ][ k - i ] + map[ j ][ k - j ]
      ( 2 <= k <= m + n, 1 <= i, j <= min { m, k - 1 }, i != j )

The above function means that the kth step can transfer from four possible positions.

O(n^3) time, O(n^3) space
*/
#include <iostream>
#include<algorithm>
using namespace std;

//For simplicity, we declare the matrix with fixed size at the beginning
int dp[100][50][50];
int map[50][50];

int MaxFour(int a, int b, int c, int d) {
    int maxab, maxcd;
    
    maxab = max(a, b);
    maxcd = max(c, d);
    
    return max(maxab, maxcd);
}


int MaximalPathGain(int map[][9], int m, int n) {

    for (int k = 2; k <= m + n; k ++) { //maximal step is m+n, we decreae m, n by one here.

        for (int i = 1; i <=m && i <= k - 1; i ++) {

            for (int j = 1; j <= m && j <= k - 1; j ++) {

               if (k != m + n && i == j)   continue; //apart the destination, two person should never reach the same grid!
                    
                dp[k][i][j] = MaxFour(dp[k - 1][i - 1][j], dp[k - 1][i][j - 1], dp[k - 1][i][j], dp[k - 1][i - 1][j - 1]) + map[i][k - i] + map[j][k - j];
            }
        }
    }
        
    return dp[m + n][m][m];

}





int main(){

    int map[9][9]={

        {1,2,3,0,4,1,5,7,0},
        {1,0,1,1,1,1,1,0,2},
        {2,0,1,1,0,3,1,0,3},
        {0,2,1,1,8,1,8,0,0},
        {2,0,1,7,1,1,1,5,0},
        {1,4,1,3,0,0,1,1,1},
        {1,5,1,0,4,0,9,6,1},
        {5,1,1,6,0,0,1,1,1},
        {1,1,1,2,3,0,2,3,1}
    };
    memset(dp, 0, sizeof(dp)); 
    cout<<MaximalPathGain(map, 8, 8)<<endl;
    return 0;

}

