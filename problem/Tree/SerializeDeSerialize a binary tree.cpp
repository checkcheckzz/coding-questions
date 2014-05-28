/*
SerializeDeSerialize a binary tree
Note: we assume the tree stores integer value and we must use another symbol (# here) to identify the NULL pointer.

*/

/*
solution: preorder traversal
O(n) time

*/



#include<iostream>
using namespace std;

struct NODE {
    int val;
    NODE* pLft;
    NODE* pRgt;
 
    NODE(int n) : val(n), pLft(NULL), pRgt(NULL) {}
};
 
void SerializeInner(char * &p, NODE* node) {
    if (node == NULL) {
        *p++ = '#';
        *p++ = ' ';
        return;
    }
    //char *  itoa ( int value, char * str, int base );
    //Converts an integer value to a null-terminated string using 
    //the specified base and stores the result in the array given
    //by str parameter.
	
    itoa(node->val, p, 10);
	
    p += strlen(p);
    *p++ = ' ';
 
    SerializeInner(p, node->pLft);
    SerializeInner(p, node->pRgt);
	
}
char* Serialize(char mem[], NODE* root) {
    char *p = mem;
    SerializeInner(p, root);
    p++;
    *p = '\0';
    return mem;
}

/////////////////////////////////////////// 
struct TOKEN {
    bool bnull;
    int val;
    TOKEN(bool b, int n) : bnull(b), val(n) {}
};
 
TOKEN GetToken(const char* &p) {
    while(*p == ' ') p++;
 
    if (*p < '0' || *p > '9') {
    
        p++;
        return TOKEN(true, 0);
    }
 
    int val = 0;
    while (*p >= '0' && *p <= '9') {
    
        val = 10*val + *p++ - '0';
        
    }    
 
    return TOKEN(false, val);
}
 
NODE*  DeSerializeInner(const char* &p) {
    TOKEN tk = GetToken(p);
	
 
    if (tk.bnull) return NULL;
 
    NODE* result = new NODE(tk.val);
    result->pLft = DeSerializeInner(p);
    result->pRgt = DeSerializeInner(p);
 
    return result;
}

NODE* DeSerialize(const char mem[]) {
    if (mem == NULL) return NULL;
 
    const char* p = mem;
    return DeSerializeInner(p);
}

int main() {

    NODE *root = new NODE(3);
    root->pLft = new NODE(1);
    root->pRgt = new NODE(4);
    char str[] = "";
    Serialize(str, root);
    cout<<str<<endl;
    const char str1[] = "3 1 # # 4 # #";
    NODE *r = DeSerialize(str1);
    cout<<r->val<<endl;
    cout<<r->pLft->val<<endl;
    cout<<r->pRgt->val<<endl;
    return 0;
}
