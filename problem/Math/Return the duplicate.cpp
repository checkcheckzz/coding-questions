/*

Given an array with numbers, find the number with most duplicates, and return all the corresponding index with equal probability.

For example, int input[]={3,7,4,3,6,1,3,6}, the function should return index 0, 3, 6 each with probability 1/3.

*/

/*

solution: scan first time to get the number with most duplicates, scan second time to output the num equally.
O(n) time, O(n) space

*/

#include<iostream>
#include<unordered_map>
using namespace std;

int MaxDupEqual(int arr[], int len) {

    int maxoccur = 0;
    int num = 0 ;
    int maxnum = 0;
    int result=0;
    unordered_map<int , int> occurmap;
    unordered_map<int , int> randompickmap;
    for (int i = 0 ; i < len ; ++i) {

        num = arr[i];
        if (occurmap.count(num)) {

            occurmap[num] += 1;

        } else {

        occurmap[num] = 1;

        }

        if (occurmap[num] > maxoccur) {

            maxoccur = occurmap[num];
            maxnum = randompickmap[num]; 
        }

    }
   
    int occur = 0;

    for (int i = 0 ; i < len ; ++i) {
  
        if (arr[i] == maxnum) {

            occur++;

            if(rand() % occur == 0)  result = i;
        }
    }

    return result;
}



int main() {

    int arr[] = {3,7,4,3,6,1,3,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<MaxDupEqual(arr, len)<<endl;
    return 0;
}


