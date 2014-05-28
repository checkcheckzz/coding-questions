/*
Given a node from a cyclic sorted linked list, insert a value into the list such that it is still a cyclic sorted list. 
The given node can be any single node in the list.
*/

/*

solution: scan 
O(n) time, O(1) space

*/
 
struct NODE {
    int val;
    NODE* next;
 
    NODE(int x) : val(x), next(NULL) {}
};

//insert x after p
void Insert(NODE* p, int x) {
    NODE* tmp = p->next;
    NODE* newnode = new NODE(x);
    p->next = newnode;
    newnode->next = tmp;
}
 
void InsertToCycleLink(NODE* node, int x) {
    assert(node != NULL);
 
    NODE* iter = node;
    NODE* big = iter; 
 
    
    do {
    
        if ((iter->val == x) || iter->val <= x && iter->next->val >= x)) { //insert at proper position
        
            return insert(iter, x);
        }    
 
        if (iter->val > big->val) big = iter; //update big
 
        iter = iter->next;

    } while (iter != node);
 
    insert(big, x);
}

