/*

Given an array and window size, return the running average in the window size.

*/

/*

solution: add new element and remove oldest element from sum.
O(n) time, O(1) space

*/

#include<iostream>
#include<cassert>
using namespace std;

void RunningAverageWindow(int arr[], int len, int windowsize) {

    assert (arr && len > 0);
    float sum=0;
   
    if (len <= windowsize) {

		for (int i = 0; i < len ; ++i) {

			sum += arr[i];
		}

		cout<<sum / (float)len<<" ";

    } else {

        for (int i = 0; i < windowsize ; ++i) {

            sum += arr[i];
        }

        cout<<sum / (float)windowsize<<" ";

        for (int i = windowsize; i < len; ++i) {

		   
            sum = sum - arr[i-windowsize] + arr [i];

            cout<<sum / (float)windowsize<<" ";
        }

	}

}

int main() {

    int arr[]={1,2,3,4,5,6};
    int windowsize = 4;
    int len = sizeof(arr)/sizeof(arr[0]);
    RunningAverageWindow(arr, len, windowsize);
    return 0;
}
