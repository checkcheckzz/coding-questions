/*

Given a set of integer, you could apply sign operation to the integer, find 
the minimum sum that is close to but  no less than 0;


input 3 5 7 11 13

output 1

*/

/*

solution: dynamic programming. The problem transfers to partition the array to two parts such that their difference is as close as possible.

part[i][j]:true if a subset of {arr[0], arr[1], ..arr[j-1]} has sum equal to i, otherwise false

O(n*sum) time, O(n*sum) space

*/

#include<iostream>
using namespace std;


int FindPartiion(int arr[], int len) {
    int sum = 0;
    int i, j;
   
    for (i = 0; i < len; ++i) {
    
      sum += arr[i];
    
    } 
   
    bool part[50][8];
     
    
    for (i = 0; i <= len; ++i) {
    
        part[0][i] = true;
       
    }
    
    
    for (i = 1; i <= sum/2; ++i) {
    
       part[i][0] = false;     
    
    }
    
    int largest = 0;
      
    // Fill the partition table in botton up manner 
    
    for (i = 1; i <= sum/2; ++i) {
    
       for (j = 1; j <= n; ++j) {
         
           if (part[i][j-1]) {  //not include arr[j]
           
              part[i][j] = true ; largest = i;
           
           }
           
           if (i >= arr[j-1]) {  //include arr[j]
           
               if(part[i - arr[j-1]][j-1]) {
             
                part[i][j] = true ; largest = i;
             
             }
		 
	   }
	}  
    }    
      
    return  sum - 2 * largest;
}     

int main() {

    int arr[5] = {3, 5, 7, 11, 13};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<FindPartiion(arr,len)<<endl;
    return 0;

}
