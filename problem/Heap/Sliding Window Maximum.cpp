/*

Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.


Input :
a[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}
k = 3
Output :
3 3 4 5 5 5 6

*/

#include<iostream>
#include<queue>
using namespace std;

/*

solution1: whenever the window moves, calculate the maximal number in the window. 
O(nk) time, O(1) space

*/

/*

solution2: use maximal heap to store k numbers.
O(nlogn) time, O(n) space

*/


typedef pair<int, int> Pair;

void MaxSlidingWindow2(int arr[], int len, int k, int window[]) {
    priority_queue<Pair> Q; 
    for (int i = 0; i < k; ++i) {
        Q.push(Pair(arr[i], i)); 
    }	
    for (int i = k; i < len; ++i) {
	
        Pair p = Q.top();
        window[i-k] = p.first;
        while (p.second <= i-k) {//pop the old elements not in new window
		
            Q.pop();
            p = Q.top();
			
        }
        Q.push(Pair(arr[i], i));
    }
    window[n-k] = Q.top().first;
}


/*

solution3:use deque to store k numbers. 
O(n) time, O(k) space

*/

void MaxSlidingWindow3(int arr[], int len, int k, int window[]) {
    deque<int> Q;
    for (int i = 0; i < k; ++i) {
  
        while (!Q.empty() && arr[i] >= arr[Q.back()]) { //elements in the deque decreases.
            Q.pop_back();
        }
     
        Q.push_back(i);
    }
  
    for (int i = k; i < len; ++i) {
  
        window[i-k] = arr[Q.front()];
        while (!Q.empty() && arr[i] >= arr[Q.back()]) {
        Q.pop_back();
      
        } 
    
        while (!Q.empty() && Q.front() <= i-k) {//pop the old elements not in new window
            Q.pop_front();
        }
    
        Q.push_back(i);
	}
  
    window[n-k] = arr[Q.front()];
}



int main() {

    int a[9] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int b[7];
    int c[7];
  
    MaxSlidingWindow2(a,9,3,b);
    MaxSlidingWindow3(a,9,3,c);
  
    for(int i = 0; i < 7; ++i) {
  
        cout<<b[i]<<" ";
	  
    }	  
    cout<<endl;
  
    for(int i = 0; i < 7; ++i) {
  
        cout<<c[i]<<" ";
    }
  
    cout<<endl;
    return 0;

}

