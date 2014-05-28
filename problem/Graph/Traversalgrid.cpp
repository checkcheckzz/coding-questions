/*


There is a rectangular grid of size m * n . Mike is in location ( x, y ) inside grid. He can move in 4 directions up, down, right and left. 
He will die if he steps outside of rectangular grid. Find the probability that bob is alive given initial position of bob as ( x, y ) 
and number of steps he moves as N. (Given that Mike moves only one step at a time).

*/

/*

solution: backtracking

*/


#include<iostream>
using namespace std;

void ProbLive(int xdim, int ydim, int startx, int starty, float &alive, float &death, int step, int N) {    
    if (step==N && startx>=0 && starty>=0 && startx<xdim && starty<ydim) {
    
        alive++;
        return;
    } else if((step<=N) && (startx<0 || starty<0 || startx>=xdim || starty>=ydim)) {
    
        death++;
        return;
    } else {
    
        probLive(xdim, ydim, startx+1, starty, alive, death, step+1, N);
        probLive(xdim, ydim, startx-1, starty, alive, death, step+1, N);
        probLive(xdim, ydim, startx, starty+1, alive, death, step+1, N);
        probLive(xdim, ydim, startx, starty-1, alive, death, step+1, N);
    }
}

int main() {
    int xdim = 5, ydim = 4;
    int startx = 3, starty = 2;
    float alive = 0.0, death = 0.0;
    int N = 8;
    ProbLive(xdim, ydim, startx, starty, alive, death, 0, N);
    cout<<a/(a+b);
    return 0;
}



