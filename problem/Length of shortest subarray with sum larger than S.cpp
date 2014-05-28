/*

Given an array, find the length of the shortest subarray, the sum of which is greater than or equal to S.

*/

/*

solution1: iterate the end and begin position
O(n^2) time, O(1) space
*/

int FindShortest1(vector<int>& num, int s) {
	int sum = 0;
	int start = 0, end = 0;
	int result = num.size() + 1;
	while (end < num.size()) {
	
		if (sum < s) sum += num[end];
		
		while (sum >= s) {
		
			result = min(result, end - start + 1);
			sum -= num[start++];
		}
		
		end++;
	}
	return result;
}

/*

solution2: use queue to store the subarray
O(n^2) worst time, O(n) space
*/

int FindShortest2(vector<int>& num,int s) {
	int len = num.size();
	queue<int> q;
	int result = len + 1, sum = 0;
	for (int i = 0; i < len; ++i) {
	
		if (q.empty() || sum < s) {
		
			q.push(num[i]);
			sum + =num[i];
		}
		
		while (!q.empty() && sum >= s) {
		
			result = min(result,(int)q.size());
			sum -= q.front();
			q.pop();
		}
	}
	
	return result;
}


/*

solution3: quick partion for the positive elements of array
O(nlogn) time, O(logn) space
*/

#include<iostream>
using namespace std;

int SearchSubarray(int arr[], int len, int k) {
	//quicksort partition

    if (1 == len || 0 == len) return len;
 
    int i = 1;
    int j = 1;
    int sum = arr[0];
    
    //the elements from arr[0] to arr[i-1] <=a[0], the elements from a[i] to a[n-1]>a[0]
    for (; j < len; ++j) {
    
        if (arr[j] >= arr[0]) {
        
            swap(arr[i], arr[j]);
            sum += arr[i++];   //all >= arr[0] element
        }
    }
 
    swap(arr[0], arr[i-1]);
 
    int partition = i-1;
    
    if (sum >= k && sum - arr[partition] < k) { //arr[0] to a[partition] is the shortest subarray
        
        return partition + 1;
        
    }    
 
    if (sum < k) {  //search right
    
        return SearchSubarray(arr+partition+1, len-partition-1, k-sum) +partition + 1;
        
    }
    
    //search left
    return SearchSubarray(arr, partition, k);
}
 
int FindShortest3(int arr[], int len, int k) {
    if (k < 0) {  //k negative is a special case
    
        int maxnum = arr[0];
        for (int i = 1; i < len; i++) {
        
            maxnum = max(arr[i], maxnum);
            
        }
        
        return maxnum >= k ? 1 : 0;
    }
 
    
    int i = 0;
    int j = len-1;
    int sumpos = 0;   //sum of all positive elements
    
    //sort a such that negative element comes first
    while (i <= j) {
    
        if (arr[i] < 0) {
     
            i++;
            
        }  else if (arr[j] >= 0) {
        
            sumpos += arr[j];
            j--;
        }
        
        else swap(arr[i], arr[j]);
    }
 
    if (i >= len || sumpos < k) return 0;   //no such subarray
    return SearchSubarray(arr+i, len-i, k);   //search from positive element
}

int main() {
    int arr[] = {1,2,3,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    int k = 6;
    cout<<FindShortest3(arr, len, k)<<endl;
    return 0;

}


