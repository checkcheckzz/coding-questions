/*

String of digits, insert + in between to make sum to be a value
For example:
Input: string = "897", target = 24 
Output: "8+9+7"

*/

/*
solution: select two numbers from k numbers, calculate all four operations, 
then k numbers become k-1 numbers, recursive execute there is only one number at last.
Note: we need to keep the order. 

*/


#include <iostream>
#include <cmath>
#include<string>
using namespace std;

#define EPS (1e-9)

int CmpTwoNumber(const double &a, const double &b) {
    if (fabs(a - b) < EPS) return 0;
    if(a - b > 0) return 1;
    return -1;
}

void CalExpression(double num[], double target, int n, string expr[]) {

    double a, b;

    string expa, expb;

    if (n == 1) {
        if (CmpTwoNumber(num[0], target) == 0) {
            cout << expr[0] << " = " << num[0] << endl;

        }
        return;
    }
    int i, j;
    i = 0;
    j = i + 1;
    a = num[i];
    b = num[j];
    int k = j;
    while(k < n -1) {
        num[k] = num[k+1];
        k++;
    }
    expa = expr[i];
    expb = expr[j];
    k = j;
    while (k < n -1) {
        expr[k] = expr[k+1];
        k++;
    }

    //a + b
    num[i] = a + b;
    expr[i] = expa + "+" + expb;
    CalExpression(num, target, n - 1, expr);

}


int main() {

    //string "897" to array num should be easy
    double num[] = {8, 9, 7};
    int len = sizeof(num)/sizeof(num[0]);
    string *expr = new string[len];
    for (int i = 0; i < len; ++i){
        expr[i] = (int)num[i] + '0';
    }
    double target = 24;
    CalExpression(num, target, len, expr);
    delete [] expr;
    return 0;
}


