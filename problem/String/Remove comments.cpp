/*

Remove the comments in a string, comments are the chars after "//" or between "//*   * //"

*/

#include<iostream>
using namespace std;

const char* RemoveComment(const char* org, char str[]) {
    if (org == NULL || str == NULL) return strN;
 
    const char* iter = org;
    char* writer = str;
    char* start = NULL;    
 
    while (*iter != '\0') {
    
        if (*iter == '/') {
        
            if (*(iter+1) == '/') {
            
                while (*iter != '\n' && *iter !='\0') { //omit all rest chars
                
                    iter++;
                }
                
                continue;
                
            } else if (*(iter + 1) == '*') {
            
                if (start == NULL) {
                
                    start = writer;  //record the previous position before /*
                    
                }    
 
                *writer++ = *iter++;
                *writer++ = *iter++;
                continue;
            }
            
        } else if (*iter == '*') {
        
            if (*(iter+1) == '/') {
            
                if (start != NULL) {
                
                    writer = start;  //jump back to the previous char of /*
                    start = NULL;
                    iter += 2; //omit */
                    continue;
                }
            }
        }
 
        *writer++ = *iter++;
    }
 
    *writer = '\0';
 
    return str;
}

int main() {

    const char text[] = "fsdf /*teert */ afdsaf";
    char res[] = "";
    char *p = res;
    RemoveComment(text, p);
    cout<<res<<endl;
    return 0;

}

