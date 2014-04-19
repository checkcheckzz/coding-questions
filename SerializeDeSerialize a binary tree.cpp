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
 
void serializeInner(char * &p, NODE* node) {
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
 
    serializeInner(p, node->pLft);
    serializeInner(p, node->pRgt);
	
}
char* serialize(char mem[], NODE* root) {
	char *p = mem;
	serializeInner(p, root);
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
 
TOKEN getToken(const char* &p) {
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
 
NODE*  deSerializeInner(const char* &p) {
    TOKEN tk = getToken(p);
	
 
    if (tk.bnull) return NULL;
 
    NODE* result = new NODE(tk.val);
    result->pLft = deSerializeInner(p);
    result->pRgt = deSerializeInner(p);
 
    return result;
}

NODE* deSerialize(const char mem[]) {
    if (mem == NULL) return NULL;
 
    const char* p = mem;
    return deSerializeInner(p);
}

int main() {

    NODE *root = new NODE(3);
    root->pLft = new NODE(1);
    root->pRgt = new NODE(4);
    char str[] = "";
    serialize(str, root);
    cout<<str<<endl;
    const char str1[] = "3 1 # # 4 # #";
    NODE *r = deSerialize(str1);
    cout<<r->val<<endl;
    cout<<r->pLft->val<<endl;
    cout<<r->pRgt->val<<endl;
    return 0;
}
