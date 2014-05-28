/*

Given an integer sequence like 2,1 5,4 6, generate one sequences such that s1 < s2 >s3 < s4 >s5 <s6 ...

*/

/*

solution1: sort the array at first, then interleave the first half and second half.
O(nlogn) time, O(1) space

solution2: put the array to a min heap. Pop elements to all even positions, then all odd positions.
O(n) time, O(n) space

*/

/*

solution3: check i and i+1, if i is even and A[i] > A[i+1] swap two values, if i is odd and A[i] < A[i+1] swap two values.
O(n) time, O(1) space

*/

#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>

using namespace std;

void OneInterleaveSeq(int arr[], int len) {

   if (len <= 1) return;
  
   for (int i = 0 ; i < len-1 ; ++i) {
   
        if((i % 2 == 0 && arr[i] > arr[i+1]) ||(i % 2 == 1 && arr[i] < arr[i+1])) {
    
        swap(arr[i],arr[i+1]);
   }

}

void Printarr(int arr[], int len) {
    for (int i=0; i<len; i++) {
	
        cout<<arr[i]<<" ";
    }		
    cout<<endl;
}


/*

Given an integer sequence like 2,1 5,4 6, generate all sequences such that s1 < s2 >s3 < s4 >s5 <s6 ...

*/

/*

solution: backtracking

*/

void AllInterleaveSeqInner(vector<int> &nums,vector<int> &cur, vector<int> &visited) {
	if (cur.size() == nums.size()) {
	
		copy(cur.begin(), cur.end(), ostream_iterator<int>(cout," "));
		cout<<endl;
		return;
	}
	
	int curlen = cur.size() + 1;
	
	for (size_t i = 0 ; i < nums.size(); ++i) {
	
		if (visited[i]) {
		
		    continue;
		
		}    
		
		//even position	
		if ((curlen & 1) && (curlen == 1 || nums[i] < cur.back())) {  
		
			visited[i] = 1;
			cur.push_back(nums[i]);
			allInterleaveSeqInner(nums,cur,visited); 
			cur.pop_back();
			visited[i] = 0;
			
		} else if ((curlen % 2 == 0) && nums[i] > cur.back()) { //odd position
		
			visited[i] = 1;
			cur.push_back(nums[i]);
			allInterleaveSeqInner(nums,cur,visited);
			cur.pop_back();
			visited[i] = 0;
		}
	}
}

void AllInterleaveSeq(vector<int>& nums) {

    if (nums.empty()) return;
	   
	
    sort(nums.begin(),nums.end());
    vector<int> cur;
    vector<int> visited(nums.size(),0);
    AllInterleaveSeqInner(nums,cur,visited);
}


int main() {

    int arr[] = {1,2,4,5,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    OneInterleaveSeq(arr, len);
    Printarr(arr,5);

    vector<int> b(5,0);
    b[0]=1,b[1]=2, b[2]=4, b[3]=5, b[4]=6;
    AllInterleaveSeq(b);
    return 0;
}
