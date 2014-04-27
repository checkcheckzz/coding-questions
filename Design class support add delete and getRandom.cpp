/*
Given a collection of integer, design a structure that supports:
 
insert(data) - insert an element
delete(data) - delete an element
getRandom() - return a random element

all O(1) time
*/
 
class Solution {
public:
    void insert(int x) {
        if (mp.find(x) != mp.end()) return;
 
        vec.push_back(x);
        mp[x] = vec.size()-1;  //start from index 0
    }
 
    void dele(int x) {
        if (mp.find(x) == mp.end()) return;
 
        int index = mp[x];
        mp.erase(mp.find(x));
 
        if (index != vec.size()-1) {
            swap(vec[index], vec[vec.size()-1]); //swap the deleted element with the last element
            mp[vec[index]] = index; //change map 
        }
 
        vec.pop_back(); //pop the deleted element
    }
 
    int getRandom() {
        return vec[rand()%vec.size()];
    }
 
private:
    unsorted_map<int, int> mp;
    vector<int> vec;
};


