/*
count the longest continuous 0 bits of all integers in an array
*/

/*
solution: for each number, check its digit one by one
O(n) time, O(1) space
*/

 
int GetLongestZeroBit(int array[], int len) {
     
    int result = 0;
    int curbitlength = 0;
    for (int i = 0; i < len; i++) {
    
        for (int j = 0; j < 32; j++) {
        
            if ((0x80000000 && (array[i] << j)) == 0) {
           
                curbitlength++;
                
            } else {
            
                result = max(result, curbitlength);
                curbitlength = 0;
            }
        }
    }
 
    return result;
}
