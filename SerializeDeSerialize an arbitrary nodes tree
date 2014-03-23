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
struct NODE 
{
    int val;
    vector<NODE*> vec;
 
    NODE(int n) : val(n), vec() {}
};
 
void serialInner(NODE* node, char*& p)
{

	
    itoa(node->val, p, 10);
    p += strlen(p);
	
    int num = node->vec.size();
    itoa(num, p, 10);
    p += strlen(p);
	

    if(node->vec.size() == 0) return;
    
    
	
    for (vector<NODE*>::iterator it = node->vec.begin(); it != pNode->vec.end(); it++) {
    
        serialInner(*it, p);
    }    
}
 
char* serialize(NODE* root, char mem[])
{
    if (NULL == mem || NULL == root) return NULL;
 
    char* p = mem;
    serialInner(root, p);
    p++;
    *p='\0';
    return mem;
}


int proc(const char*& p)
{
    
 
    int val = 0;
    
    while (*p >= '0' && *p <= '9' && *p!=' ') {
    
        val = 10 * val + *p++ - '0';
        
    }
    
    p++;
    return val;
}
 
NODE* deserialInner(const char*& p)
{
	
    
    int val = proc(p);
    
    NODE* result = new NODE(val);
    
    val = proc(p);

    int childnum = val;
   

    for (int i = 0; i < childnum; ++i) {
    
        result->vec.push_back(deserialInner(p));
    
    }    
 
    return result;
}
 
NODE* deSerialize(const char mem[])
{
    if (NULL == mem) return NULL;
 
    const char* p = mem;
    return deserialInner(p);
}

int main()
{
    
	NODE *root1 = new NODE(3);
	NODE *p1 = new NODE(1);
	

	NODE *p2 = new NODE(2);
	
	NODE *p3 = new NODE(4);
	
	root1->vec.push_back(p1);
	root1->vec.push_back(p2);
	root1->vec.push_back(p3);
	
	
	char str[] = "";

	serialize(root1,str);
	
	cout<<str<<endl;
    

	
	const char mem1[] = "3 3 1 0 2 0 4 0";
	
	NODE *root = deSerialize(mem1);
	
	cout<<root->val<<endl;
	
	for (vector<NODE*>::iterator it = root->vec.begin(); it != root->vec.end(); it++) {
	
	     cout<<(*it)->val<<endl;
		
	}	
		
	return 0;	

}
