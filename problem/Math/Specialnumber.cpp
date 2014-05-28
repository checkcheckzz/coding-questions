/*

Find all numbers less than N, such that n = a^3 + b^3 = c^3 + d^3, where a, b, c, d are non negative numbers.

*/

/*
solution: store the qubic of all factors between 1 to n^1/3. Iterate i, j, suppose the sum of their qubic is k, 
record the time of k occurance in an arr, if arr[k] == 2, output k.

O(n^2/3) time, O(n) space

*/

#include<iostream>
#include<vector>
using namespace std;

void TaxiCub(int n) {

    int limit = n; 
    vector<int> factor(n+1,0);
    vector<int> visited(n+1,0);
    for (int i = 1 ;i * i * i <= n; i++) {
        factor[i] = i*i*i; 
    }
    for (int i = 1 ; i * i *i <= n;i++) {

        for (int j  = i; j * j * j <= n;j++){
           
            int sum = factor[i] + factor[j];
            if (sum > limit) continue;

            if ( visited[sum] < 2 ) visited[sum]++;

            if (visited[sum] == 2) {

                cout<<sum<<endl;
               
            }
        }
        
    }

}

int main(){

    TaxiCub(10000);
    return 0;
}
