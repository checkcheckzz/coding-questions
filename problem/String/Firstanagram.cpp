/*

Find the first anagram's first index of a given string in another string.
If it does not exist, return -1.

*/

/*
solution: use a sliding window to save and count the change of char symbol frequency

O(n) time, O(1) space, where n is the length of string we search.
*/

#include<iostream>
#include<cassert>
using namespace std;
 
//src points to the target string, str points to the string we search
int FindFirstAnagram(char *str, char *src) {

    assert(str && src);
    int srcl = strlen(src);
    int strl = strlen(str);
    if (srcl > strl) return -1;
 
    char *p = src;
    int nfind[256];
    memset(nfind, 0, sizeof(nfind));
	//number of char symbols
    int count = 0;
    while(*p != 0) {
        if (nfind[*p]++ == 0)
            count++;
        p++;
    }
    int afind[256];
    memset(afind, 0, sizeof(afind));
 
    int match = 0;
    char *iter = str;
    for (int i = 0; i < srcl; i++) {

        if (++afind[*iter] == nfind[*iter])
            match++;
        iter++;
    }
 
    while (*iter != 0 && match != count){

		//if it will match at the end of windwow by increase one count
        if (afind[*iter] + 1 == nfind[*iter])
            match++;
		//if it already match at the end of windwow
        if (afind[*iter] == nfind[*iter] && nfind[*iter] != 0)
            match--;
		//it it will match at the begin of window by decrease on count
        if (afind[*(iter - srcl)]-1 == nfind[*(iter-srcl)] && nfind[*(iter-srcl)] != 0)
            match++;
		//if it already match at the begin of window
        if (afind[*(iter - srcl)] == nfind[*(iter - srcl)])
            match--;
 
        afind[*iter]++;
        afind[*(iter - srcl)]--;
        iter++;
    }
 
    return (match == count) ? (iter-str-srcl) : -1;
}

int main() {

    char *l = "brafasfjknvasfasadsaraa";
    char *s = "asff";
    cout<<FindFirstAnagram(l,s)<<endl;
    return 0;
}