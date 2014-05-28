/*

Find the position of the most significant digit of a postive number in binary format.

*/


/*

solution1: scan to check bit by bit
O(bits) time, O(1) space

*/


/*

solution2: binary search
O(log(bits)) time, O(1) space

*/

#include<iostream>
using namespace std;


int GetMSD1(unsigned int num) {

	int result = -1;
    while (num > 0) {

         num = num>>1;
         result++;
    }
    return result;
}

int GetMSD2(unsigned int num) {

   int result = -1;
   int low = 0, high = sizeof(int) * 8-1; //31
      while (low <= high) {

           int mid = low + (high - low) / 2;
           unsigned int mask = 1 << mid;
           if (mask & num) {
                result = mid;
           }
           if (mask >= num) {

                high = mid -1;

		   } else {
                low = mid + 1;
		   }
       }

   return result;

}

int main() {

    unsigned int num = 32;
    cout<<GetMSD1(num)<<endl;
    cout<<GetMSD2(num)<<endl;
    return 0;
}
