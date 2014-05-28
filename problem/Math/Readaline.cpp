/*

Read a line from a file randomly.
Follow up: 
Read k lines from a file randomly.
Assume you don't know the total number of lines in this file.

*/

/*
solution: 
first q: read the file once, for each line, select each line i with probability 1/i, and replace origin stored line
O(n) time, O(len) space, len is the maximal length of each line
second q: reservoir sampling
read the file once, read and store first 1 to k lines, from line i (i>k)£¬replace the current read line with 
one of stored k lines with probability k / i.
O(n) time, O(k*len) space
*/


#include<iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAX_LINE_LEN 4096

void ReadALine(FILE *file) {

    char linebuffer[MAX_LINE_LEN];
    char selection[MAX_LINE_LEN];
    int i = 1;
    while (fgets(linebuffer, MAX_LINE_LEN, file) != NULL) {
        if (rand()%i == 0) {
            strcpy(selection, linebuffer);
        }
        ++i;
    }
    puts(selection);

}


int main() {

    srand(time(0));
    FILE *file = fopen("test.txt", "r");
    ReadALine(file);
    fclose(file);
    return 0;

}
