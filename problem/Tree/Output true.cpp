/*

Given a function which can return true with probability 0.5, write a function which can return ture with any probability.

solution: from peking2 at mitbbs

*/

/*

solution: suppose you want to the function return true with probability 0.4, which means it returns false with 0.6
If you get false from prob(), you can return false because 0.5 is smaller than 0.6. If get true from prob(), you have
to subtract 0.5 from to 0.6, you need to a function return false with probability 0.2 next time.
It is similar when we want  to return true with probability larger than 0.5


*/

#include<iostream>
#include<time.h>
using namespace std;

bool Prob() {

    int i = rand();
    if (i % 2 == 0) {

        return true;

    } else {

        return false;

    }
}

bool ProbAny(double probability, bool value ) {

    if (probability < 0.5) {
	
        return ProbAny(1.0 - probability,!value);

    } else if (Prob() == value) {

        return value;

    } else {

        return ProbAny((probability  - 0.5) * 2, value);

    }

}

int main() {

    srand (time(NULL));
	
    for (int i = 0; i< 20; ++i) {

        cout<<ProbAny(0.3, true)<<endl;
    }
    return 0;

}
