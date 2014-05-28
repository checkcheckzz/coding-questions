/*

Given a positive number N, print all possible combinations of non-negative integer sum to N.

For example:

suppose N=5, print:

1+1+1+1+1
1+1+1+2

...

*/

/*

solution: Usually, we solve combination problem using backtrakcing.
For each number sum, we iterate all integers from 1 to sum. Print
the result when sum == 0. In order to remove duplicates such as 1 + 2 and 
2 + 1, we only iterate from factor larger than previous one.

*/

#include<iostream>
#include<vector>
using namespace std;


void Printcombination(vector<int> vec) {

    vector<int>::iterator it = vec.begin();

    for (; it != vec.end(); ++it) {

        cout<<*it<<" ";

    }
	
    cout<<endl;
}


void Search(vector<int>& comb, int num, int target) {

    if ( num ==0 ) {

        Printcombination(comb);
        return;
    }

    if ( num < 0  )  return;

    int i = num == target? 1 : comb.back(); //always iterate from the factor larger than previous one

    for (; i <= num; ++i) {
        comb.push_back(i);
        Search(comb, num - i, target);
        comb.pop_back();
	}
}

int main() {

    vector<int> vec;
    int num = 6;
    int target = num;
    Search(vec, num, target);
    return 0;
}






