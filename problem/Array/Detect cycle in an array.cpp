/*
Given an array of integers where each element points to the index of the next element 
how would you detect if there is a cycle in this array

Note: if the element of array is in range[0, n-1], where n is the length of array, then there must be at least one cycle.
Thus, the element may be negative or out of range[0,n-1]

/*

/*

solution1:

For a particular index, use two pointers, one pointer moves one step each time, the other pointer move two steps each time.
If the pointers ever meet together (besides the start point) before one of the pointer reaches the end, then there is a loop. 
Otherwise, there isn't.

O(n) time, O(1) space

solution2:

use two sets, one is to record all visited index in the array, another one is to record the visited index in current possible cycle
O(n) time, O(n) space

*/


#include<iostream>
#include<unordered_set>
using namespace std;

bool DetectCycle1(int arr[], int len) {
    
    int slow = 0;
    int fast = 0;
    int cur = 0;
    
    while (cur < len) {
    
        if (arr[slow] >= 0 && arr[slow] < len) {
        
            slow = arr[slow];
            
        } else {
        
            ++slow;
            fast = slow;
            cur = slow;
            continue;
        }
        
        int i = 0;
        while (i < 2 && arr[fast] >= 0 && arr[fast] < len) { //move fast two steps one time
        
            fast = arr[fast];
            ++i;
        }
        
        if (i < 2) { //less than two steps
        
            ++fast;
            slow = fast;
            cur = fast;
            
        } else { //already move two steps
        
                 if (fast == slow) { //if a cycle exists, they must meet
             
                     return true;
                     
                 } 
            
        }
    }
    
    return false;
}

bool DetectCycle2(int arr[], int len) {
    unordered_set<int> s, visited;
    
    for (int i = 0; i < len; ++i) {
    
         if (visited.find(i) == visited.end()) { //i is not visited
		            
            int curr = i;
            while (curr >= 0 && curr < len) { // a cycle only occur in this range
		
                if (s.find(curr) != s.end()) { //find a visted index
				
                    return true;
                }
                
                s.insert(curr); 
                visited.insert(curr);
                curr = arr[curr];
            }
            
            s.clear();
        }
    }
    
    return false;
}

int main() {

    int c[4] = {-1,2,3,1};
    int e[4] = {3,-2,-3,0};
    int f[3] = {-1,2,3};
    cout<<DetectCycle2(c,4)<<endl;
    cout<<DetectCycle2(e,4)<<endl;
    cout<<DetectCycle2(f,3)<<endl;
    cout<<DetectCycle1(c,4)<<endl;
    cout<<DetectCycle1(e,4)<<endl;
    cout<<DetectCycle1(f,3)<<endl;;
    return 0;
}

