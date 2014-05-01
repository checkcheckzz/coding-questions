/*

There are a lot of parentheses. The number of () is n1, 
the number of [] is n2, and the number of {} is n3.
Generate all possible legal combination of using these parentheses.
*/

/*

solution: for each choice, you can choose one of three left parentheses, 
or choose one of three right parentheses, matching the latest left parentheses.

*/


#include<iostream>
#include<string>
using namespace std;

int count = 0;


string rightPart(string left) {
    if (left == "(") return ")";
    if (left == "[") return "]";
    return "}";
}

void generateParenthesesInner(int n1, int n2, int n3, string result, string stack) {
	  

    if (n1 == 0 && n2 == 0 && n3 == 0 && stack.size() == 0) {
        count++;
        cout<<count<<":"<<result<<endl;
        return;
    }
            
    if (stack.size() > 0){

        generateParenthesesInner(n1, n2, n3, result + rightPart(stack.substr(0, 1)), stack.substr(1));
    }
        
    if (n1 > 0){

        generateParenthesesInner(n1 - 1, n2, n3, result + "(", "(" + stack);
    }
        
    if (n2 > 0){
        generateParenthesesInner(n1, n2-1, n3, result + "[",  "[" + stack);
    }

    if (n3 > 0){
        generateParenthesesInner(n1, n2, n3-1, result + "{",  "{" + stack);
    }
}

void generateParentheses(int n1, int n2, int n3){

    generateParenthesesInner(n1, n2, n3, "", "");

}

int main(){

    int n1 = 1, n2 = 1, n3 = 1;
    generateParentheses(n1,n2,n3);
    return 0;

}
