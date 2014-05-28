/*
Given a positive number and  k, delete k digits of this number to get the smallest number.
For example:
Input: num = 42130, k =1
Output: 2139
*/

/*
solution1: change the int to string. Scan the string first k digits from left, get the minposition of the smallest digit. 
Then, delete the first k digits and call the function again on the rest substring from minposition+1 to the end.
O(n*k) time, O(1) space
*/

/*
solution2: use deque, very similar to the sliding minimal Window problem.
O(n) time, O(k) space
*/

#include<iostream>
#include<cassert>
#include<string>
#include<queue>
using namespace std;

typedef pair<int, int> Pair;

string DeleteKDigits1Inner(string num, int start, int end, int k) {

	if (end - start <= k || k <0) return "";

	int minDigit = 10;
	int minPosition = -1;

	for (int i = start; i < start+k; ++i) {

		int tmp = num[i] - '0';

		if (tmp < minDigit) {

			minDigit = tmp;
			minPosition = i;

        }
    }

    return num[minPosition] + DeleteKDigits1Inner(num, minPosition + 1, end, k - (minPosition-start) );

}


int DeleteKDigits1(int num, int k) {

	assert(num > 0 && k >=0 );

	char p[32];
		
	itoa(num, p, 10);

	string str = p;

	string result = DeleteKDigits1Inner(str, 0, str.length(), k);

	int finalnum = 0;

	size_t iter = 0;

	while (iter < result.length()) {

		finalnum = 10 * finalnum + (result[iter]-'0');
		iter++;

	}

	return finalnum;

}



string DeleteKDigits2Inner(string num, int k) {

	deque<pair<int, char>> q;

	if (num.length() <= k) return "";

	for (int i = 0; i< k ; ++i) {

		while (!q.empty() && q.back().second > (num[i] - '0')) {
			q.pop_back();
		}
		q.push_back(Pair(i, num[i]));
	}

	string res = "";

	for (int i = k; i < num.length(); ++i) {

		res.push_back(q.front().second);
		q.pop_front();

		while (!q.empty() && q.back().second > (num[i] - '0')) {
			  q.pop_back();
		}

		while (!q.empty() && q.front().first < i - k) {
			  q.pop_front();
		}
		q.push_back(Pair(i, num[i]));
	
    }


    return res;
}


int DeleteKDigits2(int num, int k) {


	assert(num > 0 && k >=0 );

	char p[32];
		
	itoa(num, p, 10);

	string str = p;

	string result = DeleteKDigits2Inner(str, k);

	int finalnum = 0;

	size_t iter = 0;

	while (iter < result.length()) {

		finalnum = 10 * finalnum + (result[iter]-'0');
		iter++;

	}

	return finalnum;

}

int main() {

  int num = 42139;
  int k = 3;
  cout<<DeleteKDigits1(num, k)<<endl;
  cout<<DeleteKDigits2(num, k)<<endl;
  return 0;
}