/*

SerializeDeSerialize an arbitrary nodes tree

*/

/*

solution: preorder traversal
O(n) time

*/



#include<iostream>
#include<vector>
using namespace std;
struct NODE  {
    int val;
    vector<NODE*> vec;
 
    NODE(int n) : val(n), vec() {}
};
 
void SerialInner(NODE* node, char*& p) {

	
    itoa(node->val, p, 10);
    p += strlen(p);	
    int num = node->vec.size();
    itoa(num, p, 10);
    p += strlen(p);
	
    if (node->vec.size() == 0) return;
    
    for (vector<NODE*>::iterator it = node->vec.begin(); it != pNode->vec.end(); it++) {
    
        SerialInner(*it, p);
    }    
}
 
char* Serialize(NODE* root, char mem[]) {
    if (NULL == mem || NULL == root) return NULL;
 
    char* p = mem;
    SerialInner(root, p);
    p++;
    *p='\0';
    return mem;
}


int Proc(const char*& p) {
    
    int val = 0;
    while (*p >= '0' && *p <= '9' && *p!=' ') {
    
        val = 10 * val + *p++ - '0';
        
    }
    p++;
    return val;
}
 
NODE *DeserialInner(const char*& p) {
	
    
    int val = Proc(p);
    
    NODE *sresult = new NODE(val);
    
    val = Proc(p);

    int childnum = val;
   

    for (int i = 0; i < childnum; ++i) {
    
        result->vec.push_back(DeserialInner(p));
    
    }    
 
    return result;
}
 
NODE *DeSerialize(const char mem[]) {
    if (NULL == mem) return NULL;
 
    const char* p = mem;
    return DeserialInner(p);
}

int main() {
    
    NODE *root1 = new NODE(3);
    NODE *p1 = new NODE(1);
    NODE *p2 = new NODE(2);
    NODE *p3 = new NODE(4);
    root1->vec.push_back(p1);
    root1->vec.push_back(p2);
    root1->vec.push_back(p3);
    char str[] = "";
    Serialize(root1, str);
    cout<<str<<endl;
    
    const char mem1[] = "3 3 1 0 2 0 4 0";
    NODE *root = DeSerialize(mem1);
    cout<<root->val<<endl;
    for (vector<NODE*>::iterator it = root->vec.begin(); it != root->vec.end(); it++) {
	
        cout<<(*it)->val<<endl;
		
    }	
    return 0;	

}
