/*

For some numner N, print all solutions such that A*B=C*D where
A, B , C and D are from 1 to N.
Suppose N=2, the output should be:

1 * 1 = 1 * 1
1 * 2 = 1 * 2
1 * 2 = 2 * 1
2 * 1 = 1 * 2
2 * 1 = 2 * 1
2 * 2 = 2 * 2


*/

/*

solution1: brute force, pseudo code:

      for i=1:N
        for j=1:N
          for all common divisors k of i*j
            if k<=N && (i*j)/k <= N
              print (i,j,k, (i*j)/k)


O(n^2.5) time, O(1) space
*/


/*

solution2: store all equal products combination and print them at last.
O(n^2) time, O(n^2) space

*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void PrintEqualProduct(int num) {

    typedef unordered_multimap<int, pair<int, int> > MultiMap;
    typedef unordered_map<int, int> ProductMap;
    MultiMap resultMap;
    ProductMap productMap;

    for (int i = 1; i <= num; ++i) {

        for (int j = 1; j <= num; ++j) {
        
            resultMap.insert( MultiMap::value_type(i*j, pair<int,int>(i, j)) );
            productMap.insert( pair<int,int>(i*j,i*j) );
        }

	}
    pair<MultiMap::const_iterator, MultiMap::const_iterator> eqRange;
    MultiMap::const_iterator it1;
    MultiMap::const_iterator it2;
    ProductMap::const_iterator it;

    for (it = productMap.begin(); it != productMap.end(); ++it) {

            eqRange = resultMap.equal_range(it->second);  //search value i*j in resultMap first element, return a range pairs 

            for (it1 = eqRange.first; it1 != eqRange.second; ++it1) {

                for (it2 = eqRange.first; it2 != eqRange.second; ++it2) {

                    cout<< it1->second.first <<" * "<<it1->second.second<<" = "<< it2->second.first <<" * "<<it2->second.second <<endl;
                }
            }
    }

}

int main() {

    int num = 4;
    PrintEqualProduct(num);
    return 0;

}