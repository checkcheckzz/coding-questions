/*

Calculate the water a two dimensional histogram can hold.

*/

/*

solution: use a visted matrix to mark visted cells. use a priority queue to store current borders.
It always pops the lowest cell. Check the cell's unvisted neighbors, if their neighbor has lower height,
store the water, push the maximium between neighbors height and current heigh to piroirty queue.

O(n*n*logn) time, O(n*n) space

*/


#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Cell {

    int x;
    int y;
    int height;
	Cell(): x(0), y(0), height(0) {}
    Cell(int _x,int _y,int _height): x(_x), y(_y), height(_height) {}

};

struct Compareto {
    bool operator() (const Cell *a, const Cell *b) {
        return  a->height > b->height;
    }
};

const int m = 3;
const int n = 3;
priority_queue<Cell*, vector<Cell*>, Compareto> minheap; 
vector<vector<bool> > visited(m, vector<bool>(n, false));
vector<vector<int> > mat(m, vector<int>(n, 0));



void Check(int x, int y, int lowest, int &result) {

    if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) return;
    if(mat[x][y] < lowest) result += lowest - mat[x][y];
    visited[x][y] = true;
    minheap.push(new Cell(x,y, max(lowest, mat[x][y])));
}

int Waterin2DHistogram() {

	int result = 0;
	//push four borders at first
    for (int i = 0; i < m; i++) {
        visited[i][0] = true;
        minheap.push(new Cell(i,0,mat[i][0]));
                
        visited[i][n-1] = true;
        minheap.push(new Cell(i,n-1,mat[i][n-1]));
    }
        
    for (int j = 1; j< n - 1 ;j++) {
        visited[0][j] = true;
        minheap.push(new Cell(0,j,mat[0][j]));
                
        visited[m-1][j] = true;
        minheap.push(new Cell(m-1,j,mat[m-1][j]));
    }

    while (! minheap.empty()) {
        Cell *curr = minheap.top();
		minheap.pop();
        Check(curr->x -1,curr->y,curr->height,result);
        Check(curr->x + 1,curr->y,curr->height,result);
        Check(curr->x,curr->y - 1,curr->height,result);
        Check(curr->x,curr->y + 1,curr->height,result);
    }
        
    return result;
}


int main() {

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = 3;

    mat[m/2][n/2] = 1;
    cout<<Waterin2DHistogram()<<endl;
    return 0;
}

