/*
A non-empty zero-indexed array A consisting of N integers is given.
A pair of integers (P, Q) is called K-complementary in array A if 0 ¡Ü P, Q <
N and A[P] + A[Q] = K.
                
For example, consider array A such that: 
A[]={1, 8, -3, 0, 1, 3, -2, 4, 5}
           
The following pairs are 6-complementary in array A: (0,8), (1,6), (4,8), (5,
5), (6,1), (8,0), (8,4). 

For instance, the pair (4,8) is 6-complementary because A[4] + A[8] = 1 + 5 
= 6.
                
Given an integer K and a non-empty zero-indexed array A consisting of 
N integers, returns the number of K-complementary pairs in array A.        
For example, given K = 6 and array A such that:
A[]={1, 8, -3, 0, 1, 3, -2, 4, 5}
                  
the function should return 7, as explained above.

*/

/*

solution: use a map record each element and the number of occurance. 
If we find k-arr[i] in the map with count > 0, if k-arr[i] ! = arr[i], add twice and decrease their counts.
if k-arr[i]=arr[i], add once and decrease arr[i] counts. 
O(n) time, O(n) space
*/

#include<iostream>
#include<unordered_map>
using namespace std;


int twoSumExtension(int arr[], int len, int k) {

        unordered_map<int, int> mp;

        int count = 0;
        for(int i = 0; i < len; i++) {

            if(mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = 1;
            } else {

                mp[arr[i]]++;
			}
        }

        for(int i = 0; i < len; i++) {

            if(mp.find(k - arr[i]) != mp.end() && mp[k - arr[i]] > 0) {
                if(arr[i] == k - arr[i]){
                    count += 1;					
                    mp[arr[i]]--;
                }
                else{
                    count += 2 * mp.count(arr[i]) * mp.count(k - arr[i]);
                    mp[arr[i]]--;
                    mp[k-arr[i]]--;
                }                
            }
        }
        return count;
}



int main(){

    int arr[]= {1, 8, -3, 0, 1, 3, -2, 4, 5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int k = 6;
    cout<<twoSumExtension(arr, len, k)<<endl;
    return 0;
}