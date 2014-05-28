/*
Sieve of Eratosthenes algorithm
*/

/*

solution: start from smallest primer number p, print p and mark 2p, 3p, 4p, ...
print the first number q greater than p without mark if it exists, then repeat the steps above for q.

*/


#include <iostream>
using namespace std;


void FlagMultiples(bool arr[], int a, unsigned int num) {
    int i = 2;
    int temp = i * a;
    while ( temp <= num ) {
        arr[ temp-1 ] = true; 
        ++i;
        temp = i * a;
    }
}
 

void SieveOfEratosthenesAlg(unsigned int num) {

    if (num < 2) {
        return;  
    } else {
        bool *visited = new bool[num];
        for (int k = 0; k < num; k++) {
            visited[k] = false;
        }

        for (unsigned int i = 1; i < num; ++i) {

            if ( visited[i] == 0 ) {
                cout<<i+1<<" ";
                FlagMultiples(visited, i+1, num);
            }
        }

        delete [] visited;
    }
	
}
 

int main() {
    unsigned int num;
    cin>>num;
    cout<<"The primer numbers below number "<<num<<" are:"<<endl;
    SieveOfEratosthenesAlg(num);
    cout<<endl;
    return 0;
}
