/*
Given a lot of user logs£¬calculate the user number during time intervals

For example£º
user1:
login_time: 0
logout_time: 1

user2:
login_time: 0
logout_time: 2

user3:
login_time: 1
logout_time: 3

ouput£º
[0 - 2): 2
[2 - 3): 1
[3 - infinite): 0

Note that you don't need output interval 0 -1 because there are two users at point 0 and
two users at point 1. The number of users don't change.


finish the function£º
struct Log
{
  float login_time;
  float logout_time;
};
void online_user(vector<Log> &logs);


*/

/*

solution: use a map to record the time point and the number of users change. When there is a login, increase the count. 
When there is a logout, decrease the count. Print the interval based on the map, 
only output the intervals with non zero changes.
O(n) time, O(n) space
*/
#include<iostream>
#include <algorithm>
#include <vector>
#include<map>
using namespace std;

struct Log {
    int login_time;
    int logout_time;
    Log(int in, int out): login_time(in), logout_time(out)
    {}
};

void OnlineUser(vector<Log> &logs) {
    if (logs.empty()) return;
    map<float, int> mp;
    for (vector<Log>::const_iterator it = logs.begin(); 
            it != logs.end(); ++it) {
        mp[it->login_time]++;
        mp[it->logout_time]--;
    }

    float prevtime = mp.begin()->first;
    int usernum = mp.begin()->second;
    for (map<float, int>::const_iterator it = ++mp.begin();
    it != mp.end(); ++it) {
        if (it->second!=0) {
        cout << "[" << prevtime << " - " << it->first << ") : " << usernum << endl;
            usernum += it->second;
            prevtime = it->first;
       }
    }
    cout << "[" << prevtime << " - " << "infinite) : 0 " << endl;
}

int main() {
    vector<Log> logs;
    logs.push_back(Log(0, 1));
    logs.push_back(Log(0, 2));
    logs.push_back(Log(1, 3));
    OnlineUser(logs);
    return 0;
}
