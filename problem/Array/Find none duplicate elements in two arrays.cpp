/*

Given two arrays, find the numbers in first array but not in the second array

*/
 

/*

solution: sort & two pointers
O(nlogn+mlogm) time, O(1) space

*/

void FindUniqueArray(int arr1[], int arr1len, int arr2[], int arr2len) {
    assert(arr1 && arr2 && arr1len > 0 && arr2len > 0);
 
    sort(arr1, arr1 + arr1len);
    sort(arr2, arr2 + arr2len);
 
    int iterarr1 = 0;
    int iterarr2 = 0;
    
    while (iterarr1 < arr1len && iterarr2 < arr2len) {
        
        if (arr1[iterarr1] <= arr2[iterarr2]) {
        
            if (arr1[iterarr1] != arr2[iterarr2]) {
            
                cout<<arr1[iterarr1]<<endl;
            }
            
            iterarr1++;
            
        } else { 
        
        iterarr2++;
        
        }
    }
 
    while ( iterarr1 <arr1len) {
    
        cout<<arr1[iterarr1++]<<endl; 
    }
    
}
