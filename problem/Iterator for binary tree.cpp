/*
Write an iterator for binary tree. 
*/

struct NODE {
    int val;
    NODE* pLft;
    NODE* pRgt;
 
    NODE(int n) : val(n), pLft(NULL), pRgt(NULL) {}
};

/*
Here is the inorder iterator.
*/

class BinaryTreeIterator {

public:
    void iterconstruct(NODE* root) { 
       buildIter(root);
     
    }
 
    NODE *Next() {
        if (stk.empty()) return NULL;
 
        NODE* ret = stk.top();
        stk.pop();
 
        BuildIter(ret->pRgt);
 
        return ret;
    }
 
private:
    void buildIter(NODE* node) {
        while (node != NULL) {
        
            stk.push(node);
            node = node->pLft;
        }
    }

    stack<NODE*> stk;
   
};



