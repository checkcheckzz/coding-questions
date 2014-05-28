/*

Given two string arrays, array1 and array2, sort the strings in array1 
according to the order strings in array2.

For example:

Input: array1={"abc","ddd"}, array2={"ddd","abc","ooo"};

output: array1 {"ddd","abc"}.
*/

/*

solution: we need to use the call the sort algorithm directly with a new comparator.
O(nlogn) time, O(m) space, n is the number of strings in array1, and m is the number of strings in array2. 

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;

unordered_map<string, int> mp;

bool LessThan(string str1, string str2) {

    int order1 = mp[str1];
    int order2 = mp[str2];
           
    if (order1 < order2) {
        return true;
    } else {

        return false;
     
    }
}


void SortTwoArray(vector<string> &arr1, vector<string> &arr2) {
    
     for(size_t i = 0;i < arr2.size(); ++i) {

        mp[arr2[i]] = i;
     }

     sort(arr1.begin(), arr1.end(), LessThan);
}


int main() {

    vector<string> arr1;
    arr1.push_back("abc");
    arr1.push_back("ddd");
    arr1.push_back("ft");
    vector<string> arr2;
    arr2.push_back("ddd");
    arr2.push_back("wt");
    arr2.push_back("ft");
    arr2.push_back("zzt");
    arr2.push_back("abc");

    SortTwoArray(arr1, arr2);
    for (size_t i = 0; i < arr1.size(); ++i) {

        cout<<arr1[i]<<endl;
    }
    return 0;
}