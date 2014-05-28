/*
Given a list of strings l1, the string follow the lexicographical order.
Now we do a one to one mapping for the chars, such as a->e, p->d, l->f, e->o,
b->...We get another list of strings l2.

Suppose we only know l2, find the mapping rule.
*/

/*
solution: 
O(n*len) time, O(26) space, n is the number of strings, and len is the average length of each string. 
*/

#include<iostream>
#include<unordered_map>
using namespace std;

void FindMapRule(string s[], int len) {

    unordered_map<char, char> rule;

    char begin = s[0][0];
    for (int i = 0; i < len - 1; ++i) {
        int j = i + 1;
        size_t k = 0;

        while (k < s[i].length() && k < s[j].length() && s[i][k] == s[j][k]) {

            k++;
        }
        rule[s[i][k]] = s[j][k]; 

        if(s[j][k] == begin) begin = s[i][k];
        
    }

    while (rule.find( begin ) != rule.end()) {
        cout<< begin << " ->" << rule[begin] <<endl;
        begin = rule[begin];
    }
}

int main() {

    string s[] = {"erg", "wrf", "er", "ett", "rftt","te","ba","bw","fw"};
    FindMapRule(s, 9);
    return 0;

}