/*

Find all the possible interleaves of two input strings.

For example:

input: ab, c
output: abc, acb, cab

*/

/*
solution: Recursion. Each time choose one char from str1 or str2, and store it in an output string, increase the index 
for str1 or str2 and output string. When the length of output is sum of both string lengths, print output.
O(n1+n2) space
*/

#include<iostream>
#include<string>
using namespace std;

void AllInterleaves(string str1, string str2, string output,int index1,int index2, int &index) {

    if (index == str1.size() + str2.size()) {

        cout<<output<<endl;
        return;
    }

    else {
        if(index1 < str1.size()) {
            output[index] = str1[index1];
			int temp = index+1;
            AllInterleaves(str1,str2,output,index1 + 1,index2, temp);
        }
        if(index2 < str2.size()) {
            output[index] = str2[index2];
			int temp = index+1;
            AllInterleaves(str1,str2,output,index1,index2 + 1, temp);
        }
    }
}

int main() {

    string str1 = "abc";
    string str2 = "de";
    int len = str1.size() + str2.size();
    string output(len, ' ');
    int index = 0; 
    AllInterleaves(str1,str2,output,0,0,index);
    return 0;
}

