/*
Implement copy on write string class in c++ 
*/

/*
Because we want to implement copy on write class, we define copy constructor, assignment operator.
In real application, we should disallow copy constructor and assignment operator.
*/

#include<iostream>
using namespace std;


class CopyOWString {
public:
    CopyOWString(const char* str) { newStr(str); }
    CopyOWString(CopyOWString& cowStr) { incRef(cowStr); }
    ~CopyOWString() { decRef(); }
	
    char* getStr(){return strcontent;}
    int* getCount(){return referencecount;}
 
    CopyOWString& operator = (const char* str);
    CopyOWString& operator = (CopyOWString& cowStr);
 
private:
    void incRef(CopyOWString& cowStr);
    void decRef();
    void newStr(const char* str);
 
    char* strcontent;
    int* referencecount;
};


/*
Increase the reference count to string
*/
void CopyOWString::incRef(CopyOWString& cowStr) {
    referencecount = cowStr.referencecount;
    strcontent = cowStr.strcontent;
    (*referencecount)++;
}

/*
Decrease the reference count to string
*/
void CopyOWString::decRef() {
    (*referencecount)--;
    if (*referencecount <= 0) {
        delete []strcontent;
        delete referencecount;
    }
}
 
void CopyOWString::newStr(const char* str) {
    strcontent= new char[strlen(str) + 1];
    strcpy(strcontent, str);
    referencecount = new int(1);
}
 
CopyOWString& CopyOWString::operator = (CopyOWString& cowStr) {
    if (this != &cowStr) {
        decRef();
        incRef(cowStr);
    }
    return *this;
}
 
CopyOWString& CopyOWString::operator = (const char* str) {
    decRef();
    newStr(str);
    return *this;
}

int main() {

    CopyOWString a("abc");
    cout<<*a.getStr()<<endl;
    cout<<*a.getCount()<<endl;
    CopyOWString b(a);
    cout<<*a.getCount()<<endl;
    a.~CopyOWString();
    cout<<*a.getCount()<<endl;
    return 0;
}

