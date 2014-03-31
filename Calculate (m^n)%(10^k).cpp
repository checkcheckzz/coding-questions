/*
Find the last 1000 digits of  5^1234566789893943.
*/

/*

solution: big number + recursion
O((log n) * k * k) time, O(k*k) space
*/

#include<iostream>
#include<cassert>
#include<string>
using namespace std;

string multiplyArrays(string num1, string num2, int k) {
        int N = num1.length(), M = num2.length();
        string res(N+M, '0');
        for (int i = N - 1; i >= 0; --i)
        {
            int carry = 0;
            int j;
            for (j = M - 1; j >= 0; --j)
            {
				//only keep res[0....k-1]
                if((N-i) + (M-j) -1 > k) break;
                int sum = carry + (res[i+j+1] - '0') + 
                          (num1[i] - '0') * (num2[j] - '0');
                res[i+j+1] = sum % 10 + '0';
                carry = sum / 10;
            }
            res[i+j+1] += carry;
        }
	
		while (res.length() > 1 && res[0] == '0'){

            res.erase(res.begin());
		}

        if (res.length() <= k) return res;

		int iter = 0;
		while(iter < res.length() - k) {

			res.replace(iter, iter + 1, "0");
			iter++;
		}
		while (res.length() > 1 && res[0] == '0'){

            res.erase(res.begin());
		}
		return res;

}


string calculate(long m, long n, int k) {

	
	assert (m > 0 && n >=0  && k >= 0 );

    if(n == 1) {

		char p[32];
        itoa(m, p, 10);
		string tmp = p;
        return tmp;

    } else if (n % 2) { // odd number

		char p[32];
        itoa(m, p, 10);
		string tmp = p;
        string result1 = calculate(m, n-1, k);
        return multiplyArrays(result1, tmp, k);

    } else {

        string result1 = calculate(m, n/2, k);
        return multiplyArrays(result1, result1, k);
    }
}



int main() {

	long m = 5;
	long n = 8;
	int k = 3;
	
	string result = calculate(m, n, k);

    cout<<result<<endl;

	return 0;


}
