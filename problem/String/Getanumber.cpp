/*
Given k numbers a0, a1, a2, a3,..., ak
Find all possible expression to using + - * / with any '(',')' to generate a
result equals to target X. 
The expression must be valid, all k number must be used but their order does not matter.
*/

/*
solution: select two numbers from k numbers, calculate all four operations, 
then k numbers become k-1 numbers, recursive execute there is only one number at last.
Note: we need to define a proper comparison function to control the precsion lost. 
O((n!)^2) time
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

    if (n == 1){
        if(cmpTwoNumber(num[0], target) == 0) {
            cout << expr[0] << " = " << num[0] << endl;
        }
        return;
    }
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            a = num[i];
            b = num[j];
            num[j] = num[n-1];
            expa = expr[i];
            expb = expr[j];
            expr[j] = expr[n-1];

            //a + b
            num[i] = a + b;
            expr[i] = "(" + expa + "+" + expb + ")";
            CalExpression(num, target, n - 1, expr);

            //a - b
            num[i] = a - b;
            expr[i] = "(" + expa + "-" + expb + ")";
            CalExpression(num, target, n - 1, expr);
            //b - a
            num[i] = b - a;
            expr[i] = "(" + expb + "-" + expa + ")";
            CalExpression(num, target, n - 1, expr);

            //a * b
            num[i] = a * b;
            expr[i] = "(" + expa + "*" + expb + ")";
            CalExpression(num, target, n - 1, expr);

            //a / b
            if (CmpTwoNumber(b, 0) != 0){
                num[i] = a / b;
                expr[i] = "(" + expa + "/" + expb + ")";
                calExpression(num, target, n - 1, expr);
            }
            //b / a
            if (CmpTwoNumber(a, 0) != 0){
                num[i] = b / a;
                expr[i] = "(" + expb + "/" + expa + ")";
                CalExpression(num, target, n - 1, expr);
			}

            //backtracking
            expr[j] = expb;
            expr[i] = expa;
            num[j] = b;
            num[i] = a;
        }
    }
}


int main() {

    double num[] = {8, 4, 2};
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



