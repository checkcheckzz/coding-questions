/*
class Contact includes a string name£¬and a vector<string>.
The vector includes some email address of this person.
For example:
#1 John1 [john@gmail.com]
#2 Mary [mary@gmail.com]
#3 John2 [john@yahoo.com]
#4 John3 [john@gmail.com, john@yahoo.com, john@hotmail.com]
#5 Bob [bob@gmail.com]
Based on the email address, group the contacts, output a  vector<vector<Contact>>.
Here #1£¬#3£¬#4 are the same person.
*/

/*

solution: use union0-find set. Build a hash table from email to name index,
union all name index with same email, group all names with the same father together,
transfer name index to the name.
O(n*k*logn) time, O(n*k) space, n is the number of names, k is the number of email per names.
*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>

using namespace std;


struct record {
    string name;
    vector<string> emails;    
};

// email -> input vector index
map<string,vector<int> > ht;

// union-find set
vector<int> f;
vector<int> ranks;

int Find(int x) {
    if (x == f[x]) return x;
	//optimization
    return f[x] = Find(f[x]);
}

void Unite(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return;
	//optimization
    if (ranks[x] < ranks[y]) {
        f[x] = y;
    }
    else {
        f[y] = x;
        if (ranks[x] == ranks[y]) {
            ranks[y]++;
        }
    }    
}

vector<vector<string> > GroupContact(vector<record> & input) {
    vector<vector<string> > res;
    size_t n = input.size();
    size_t k, i;
    // hash stat email -> name index
    for (k = 0; k < n; k++) {        
        for (i = 0; i < input[k].emails.size(); i++) {
            string email = input[k].emails[i];
            ht[email].push_back(k);
        }
    }
    f.resize(n);
    ranks.resize(n);
    for (i = 0; i < n; i++) {
        f[i] = i;
        ranks[i] = 0;
    }
    // union all names which has same email
    map<string,vector<int> >::iterator it;
    for (it = ht.begin(); it != ht.end(); it++) {
        vector<int>  &v = it->second;
        for (i = 0; i < v.size()-1; i++) {
            Unite(v[i], v[i+1]);
        }
    }
    // group all names with the same father together
    map<int,vector<int> > mp;
    for (i = 0; i < n; i++) {
        mp[Find(i)].push_back(i);
    }
	//transfer index to names
    map<int,vector<int> >::iterator it2;
    for (it2 = mp.begin(); it2 != mp.end(); it2++) {
        vector<int> & v = it2->second;
        vector<string> vs;
        for (size_t i = 0; i < v.size(); i++) {
            vs.push_back(input[v[i]].name);
        }
        res.push_back(vs);
    }
    return res;
}


int main() {
    vector<record> input(5);
    input[0].name = "John1";
    input[0].emails.push_back("john@gmail.com");

    input[1].name = "Mary";
    input[1].emails.push_back("mary@gmail.com");

    input[2].name = "John2";
    input[2].emails.push_back("john@yahoo.com");

    input[3].name = "John3";
    input[3].emails.push_back("john@gmail.com");
    input[3].emails.push_back("john@yahoo.com");
    input[3].emails.push_back("john@hotmail.com");

    input[4].name = "Bob";
    input[4].emails.push_back("bob@gmail.com");    

 
    vector<vector<string> > res = GroupContact(input);

    for (size_t k = 0; k < res.size(); k++) {
        printf("group %d: ", k+1);
        for (size_t i = 0; i < res[k].size(); i++) {
            cout << res[k][i] << " ";
        }
        cout << endl;
    }

    return 0;
}

