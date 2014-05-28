/*
Given an array of numbers, nums, return an array of numbers products, where 
products[i] is the product of all nums[j], j != i.

For example: 
Input : [1, 2, 3, 4, 5]
Output: [(2*3*4*5), (1*3*4*5), (1*2*4*5), (1*2*3*5), (1*2*3*4)]
      = [120, 60, 40, 30, 24]
You must do this in O(n) without using division.
*/


/*
solution: scan two times.
O(n) time, O(1) space
*/

/*
Input: array input[] is the input array, len is the size of array input[].
Output: array output[] is the output array
*/
 
void BuildArray(int input[], int len, int output[]) {
    output[len-1] = 1;
    // output[i]=input[i+1]*intput[i]*......*input[n-1];
    for (int i = len-2; i >= 0; i--) {  
        output[i] = output[i+1] * intput[i+1];
    }	
    int allrestinput = 1;
    
    // add input[0]*...input[i-1] to output[i]
    for (int i = 1; i < len; i++) {
        allrestinput *= input[i-1];
        output[i] = output[i] * allrestinput;
    }   
}    
  
