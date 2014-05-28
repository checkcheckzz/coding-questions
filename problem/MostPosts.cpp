/*

There is an non negative integer array. Each number represent the author ID of a post in a forum.
We already know that an author writes more than half of all posts in this forum, find this author ID.


Follow up: suppose that three authors each writes more than 1/4 posts in this forum, find the three authors.
*/

/*

solution1: brute force. sort the array first, and scan the array once to find the target ID. 
O(nlogn) time, O(1) space

solution2: whenever we delete two different IDs, in the rest array, there are still more than half target IDs.
Just scan the array, if the same Id appears, increase a count, otherwise, decrease a count. when the count is zero,
record the id. Return the id at last.
O(n) time, O(1) space

*/
#include<iostream>
using namespace std;

int FindIdWithMostPosts(int arr[], int len) {  
 
    int id = -1;  
    int nTimes, i;  
    for(i = nTimes = 0; i < len; i++)  {  

        if(nTimes == 0)  {

            id = arr[i], nTimes = 1;  
        } else {  

            if(id == arr[i]) {

                nTimes++; 

            } else {  

                nTimes--;  
            }  
	    }

    }

    return id;
}

/*

Follow up solution: simiar as above, we delete four different Ids each time, the problem condition remains unchanged.
O(n) time, O(1) space

*/

void FindIdWithMoreThanQuarterPosts(int arr[], int len, int Ids[]) {
    int Id = -1;
    int nTimes[3], i;
    nTimes[0] = nTimes[1] = nTimes[2] = 0;
    Ids[0] = Ids[1] = Ids[2] = -1;
    for (i = 0; i < len; i++) {

        if(arr[i] == Ids[0]) {
             nTimes[0]++;
        } else if(arr[i] == Ids[1]) {
             nTimes[1]++;
        } else if(arr[i] == Ids[2]) {
             nTimes[2]++;
        } else if(nTimes[0] == 0) {
             nTimes[0] = 1;
             Ids[0] = arr[i];
        } else if(nTimes[1]==0) {
             nTimes[1] = 1;
             Ids[1] = arr[i];
        } else if(nTimes[2]==0) {
             nTimes[2] = 1;
             Ids[2] = arr[i];
        } else {
             nTimes[0]--;
             nTimes[1]--;
             nTimes[2]--;
        }
    }

}


int main() {

    int arr[] = {5, 0, 1, 5, 3, 5, 5, 4, 5, 2, 0, 5, 5, 5};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<FindIdWithMostPosts(arr, len)<<endl;
    int arr1[] = {1, 2, 3, 5, 3, 2, 1};
    int len = sizeof(arr1)/sizeof(arr1[0]);
    int Ids[3] = {-1, -1, -1};
    FindIdWithMoreThanQuarterPosts(arr1, len, Ids);
    for (int i = 0; i <= 2; ++i) {
        cout<<Ids[i]<<endl;
    }
    return 0;

}

