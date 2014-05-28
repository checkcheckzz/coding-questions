/*

Given a squre, the coordinates of a rabbit and the coordinates of the carrots, 
find out the number of carrots that the rabbit can eat. This is only one rabbit and all rest are carrots.

The rabbit can only eat carrots which are in its own row, own column or in any of the diagonals.

*/

/*

solution: Just scan the grid to check the row index difference, column index difference or column index difference/row index difference.
O(n^2) time, O(1) space

*/


#include<iostream>
#include<vector>
using namespace std;

int NumCarrot(int x, int y, int len) {

	int result = 0;

	for(int i = 0; i < len; ++i) {
	
		for(int j = 0; j < len; ++j) {

			int diffx = x - i;
			int diffy = y - j;

			if (diffx == 0 && diffy != 0) {
			
			   result++;
			  
			}  else if (diffy == 0 && diffx != 0) { 
			  
			   result++;
			  
			}  else if ((diffx != 0 && diffy != 0) && (diffy / diffx == 1 || diffy / diffx == -1)) {
			
			   result++;
			
			}

		}

	}

	return result;

}

int main() {

  int len = 5;	 
  cout<<NumCarrot(2,2, len)<<endl;
  return 0;
  
}

